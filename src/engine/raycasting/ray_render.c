/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:37:48 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/15 13:38:35 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ray.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(int *)pixel);
}

t_img	*get_wall_texture(t_ray *ray, t_data *data)
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

static void	draw_wall_textured(t_data *data, t_ray *ray, int x, t_img *texture)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	tex_x = (int)(ray->wall_x * texture->width);
	step = 1.0 * texture->height / ray->line_height;
	tex_pos = (ray->draw_start - W_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos % texture->height;
		tex_pos += step;
		my_mlx_pixel_put(&data->render_img, x, y++,
			get_texture_pixel(texture, tex_x, tex_y));
	}
}

void	draw_wall_column(t_data *data, t_ray *ray, int x)
{
	int		y;
	t_img	*texture;

	texture = get_wall_texture(ray, data);
	y = 0;
	while (y < ray->draw_start)
		my_mlx_pixel_put(&data->render_img, x, y++,
			data->texture.ceil_color);
	draw_wall_textured(data, ray, x, texture);
	y = ray->draw_end;
	while (y < W_HEIGHT)
		my_mlx_pixel_put(&data->render_img, x, y++,
			data->texture.floor_color);
}
