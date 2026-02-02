/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slender_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:00:57 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 16:00:59 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

static void	draw_slender_col(t_data *data, t_sprite_proj *p,
	t_img *tex, int stripe)
{
	int	y;
	int	tex_x;
	int	tex_y;
	int	d;
	int	color;

	tex_x = (int)(256 * (stripe - (-p->width / 2 + p->screen_x))
			* tex->width / p->width) / 256;
	y = p->draw_start_y;
	while (y < p->draw_end_y)
	{
		d = y * 256 - W_HEIGHT * 128 + p->height * 128;
		tex_y = ((d * tex->height) / p->height) / 256;
		color = get_texture_pixel(tex, tex_x, tex_y);
		if (!(color & 0xFF000000))
			my_mlx_pixel_put(&data->render_img, stripe, y, color);
		y++;
	}
}

static void	draw_slender_sprite(t_data *data, t_sprite_proj *p)
{
	int		stripe;
	t_img	*tex;

	tex = &data->slender.frames[data->slender.cur_frame];
	stripe = p->draw_start_x;
	while (stripe < p->draw_end_x)
	{
		if (p->transform_y > 0 && stripe >= 0 && stripe < W_WIDTH
			&& p->transform_y < data->sprites.z_buffer[stripe])
			draw_slender_col(data, p, tex, stripe);
		stripe++;
	}
}

static void	clamp_slender_bounds(t_sprite_proj *p)
{
	p->draw_start_y = -p->height / 2 + W_HEIGHT / 2;
	if (p->draw_start_y < 0)
		p->draw_start_y = 0;
	p->draw_end_y = p->height / 2 + W_HEIGHT / 2;
	if (p->draw_end_y >= W_HEIGHT)
		p->draw_end_y = W_HEIGHT - 1;
	p->draw_start_x = -p->width / 2 + p->screen_x;
	if (p->draw_start_x < 0)
		p->draw_start_x = 0;
	p->draw_end_x = p->width / 2 + p->screen_x;
	if (p->draw_end_x >= W_WIDTH)
		p->draw_end_x = W_WIDTH - 1;
}

static void	project_slender(t_data *data, t_sprite_proj *p)
{
	double	inv;
	double	sx;
	double	sy;

	sx = data->slender.x - data->player.x;
	sy = data->slender.y - data->player.y;
	inv = 1.0 / (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	p->transform_x = inv * (data->player.dir_y * sx
			- data->player.dir_x * sy);
	p->transform_y = inv * (-data->player.plane_y * sx
			+ data->player.plane_x * sy);
	p->screen_x = (int)((W_WIDTH / 2)
			* (1 + p->transform_x / p->transform_y));
	p->height = abs((int)(W_HEIGHT / p->transform_y));
	p->width = p->height;
	clamp_slender_bounds(p);
}

void	render_slenderman(t_data *data)
{
	t_sprite_proj	proj;

	if (!data->slender.active)
		return ;
	project_slender(data, &proj);
	if (proj.transform_y > 0)
		draw_slender_sprite(data, &proj);
}
