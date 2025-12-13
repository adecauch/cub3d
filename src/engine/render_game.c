/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:35:33 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/11 13:50:52 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

//structure pour les variables de raycasting
typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

// dessine un pixel rapidement dans l'image
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

// récupère la couleur d'un pixel dans une texture
int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(int *)pixel);
}

// initialise le rayon pour une colonne x donnée
static void	init_ray(t_ray *ray, t_data *data, int x)
{
	ray->camera_x = 2 * x / (double)W_WIDTH - 1;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

// calcule la direction et la distance initiale
static void	calculate_step_and_side_dist(t_ray *ray, t_data *data)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_dist_y;
	}
}

// algorithme DDA : avance jusqu'à toucher un mur
static void	perform_dda(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

// calcule la distance perpendiculaire au mur
static void	calculate_wall_distance(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player.x
			+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player.y
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

// calcule où exactement on frappe le mur (coordonnée X sur la texture)
static void	calculate_wall_x(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->wall_x = data->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = data->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

// détermine quelle texture utiliser selon le côté du mur
static t_img	*get_wall_texture(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&data->texture.east);
		else
			return (&data->texture.west);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (&data->texture.south);
		else
			return (&data->texture.north);
	}
}

// lance un rayon et remplit la structure ray
static void	cast_ray(t_data *data, int x, t_ray *ray)
{
	init_ray(ray, data, x);
	calculate_step_and_side_dist(ray, data);
	perform_dda(ray, data);
	calculate_wall_distance(ray, data);
	calculate_wall_x(ray, data);
}

// dessine une colonne verticale (mur) avec texture
static void	draw_wall_column(t_data *data, int x, t_ray *ray, int draw_start, int draw_end)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	t_img	*texture;
	int		line_height;

	texture = get_wall_texture(ray, data);
	tex_x = (int)(ray->wall_x * texture->width);
	line_height = (int)(W_HEIGHT / ray->perp_wall_dist);
	step = 1.0 * texture->height / line_height;
	tex_pos = (draw_start - W_HEIGHT / 2 + line_height / 2) * step;
	y = 0;
	while (y < draw_start)
		my_mlx_pixel_put(&data->render_img, x, y++, data->texture.ceil_color);
	while (y < draw_end)
	{
		tex_y = (int)tex_pos % texture->height;
		tex_pos += step;
		my_mlx_pixel_put(&data->render_img, x, y++,
			get_texture_pixel(texture, tex_x, tex_y));
	}
	while (y < W_HEIGHT)
		my_mlx_pixel_put(&data->render_img, x, y++, data->texture.floor_color);
}

void	render_game(t_data *data)
{
	int		x;
	t_ray	ray;
	int		line_height;
	int		draw_start;
	int		draw_end;

	x = 0;
	while (x < W_WIDTH)
	{
		cast_ray(data, x, &ray);
		line_height = (int)(W_HEIGHT / ray.perp_wall_dist);
		draw_start = -line_height / 2 + W_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + W_HEIGHT / 2;
		if (draw_end >= W_HEIGHT)
			draw_end = W_HEIGHT - 1;
		draw_wall_column(data, x, &ray, draw_start, draw_end);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->render_img.img, 0, 0);
}
