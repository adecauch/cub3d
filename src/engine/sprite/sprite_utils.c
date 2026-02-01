/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:54:02 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/01 22:54:45 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

static void	sort_order(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < data->sprites.count - 1)
	{
		j = i;
		while (++j < data->sprites.count)
		{
			if (data->sprites.dist[data->sprites.order[j]]
				> data->sprites.dist[data->sprites.order[i]])
			{
				tmp = data->sprites.order[i];
				data->sprites.order[i] = data->sprites.order[j];
				data->sprites.order[j] = tmp;
			}
		}
	}
}

void	sort_sprites(t_data *data)
{
	int		i;
	double	dx;
	double	dy;

	i = -1;
	while (++i < data->sprites.count)
	{
		data->sprites.order[i] = i;
		dx = data->sprites.arr[i].x - data->player.x;
		dy = data->sprites.arr[i].y - data->player.y;
		data->sprites.dist[i] = dx * dx + dy * dy;
	}
	sort_order(data);
}

static void	clamp_sprite_bounds(t_sprite_proj *p)
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

void	project_sprite(t_data *data, t_sprite *sp, t_sprite_proj *p)
{
	double	inv_det;
	double	sx;
	double	sy;

	sx = sp->x - data->player.x;
	sy = sp->y - data->player.y;
	inv_det = 1.0 / (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	p->transform_x = inv_det * (data->player.dir_y * sx
			- data->player.dir_x * sy);
	p->transform_y = inv_det * (-data->player.plane_y * sx
			+ data->player.plane_x * sy);
	p->screen_x = (int)((W_WIDTH / 2)
			* (1 + p->transform_x / p->transform_y));
	p->height = abs((int)(W_HEIGHT / p->transform_y));
	p->width = p->height;
	clamp_sprite_bounds(p);
}
