/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:46:22 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/01 22:46:25 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

static void	draw_sprite_col(t_data *data, t_sprite_proj *p,
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

static void	draw_single_sprite(t_data *data, t_sprite *sp, t_sprite_proj *p)
{
	int		stripe;
	t_img	*tex;

	tex = get_sprite_frame(data, sp);
	stripe = p->draw_start_x;
	while (stripe < p->draw_end_x)
	{
		if (p->transform_y > 0 && stripe >= 0 && stripe < W_WIDTH
			&& p->transform_y < data->sprites.z_buffer[stripe])
			draw_sprite_col(data, p, tex, stripe);
		stripe++;
	}
}

void	render_sprites(t_data *data)
{
	int				i;
	int				idx;
	t_sprite_proj	proj;

	if (data->sprites.count == 0)
		return ;
	sort_sprites(data);
	i = 0;
	while (i < data->sprites.count)
	{
		idx = data->sprites.order[i];
		if (data->sprites.arr[idx].active)
		{
			project_sprite(data, &data->sprites.arr[idx], &proj);
			if (proj.transform_y > 0)
				draw_single_sprite(data, &data->sprites.arr[idx], &proj);
		}
		i++;
	}
}
