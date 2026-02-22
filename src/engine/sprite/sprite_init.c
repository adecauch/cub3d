/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:46:08 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/22 19:35:54 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

static int	count_sprites(char **map, int *n_collect, int *n_exit)
{
	int	i;
	int	j;

	*n_collect = 0;
	*n_exit = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				(*n_collect)++;
			else if (map[i][j] == 'X')
				(*n_exit)++;
		}
	}
	return (*n_collect + *n_exit);
}

static int	alloc_sprite_buffers(t_sprites *sp, int count)
{
	sp->arr = malloc(sizeof(t_sprite) * count);
	if (!sp->arr)
		return (1);
	sp->order = malloc(sizeof(int) * count);
	if (!sp->order)
		return (1);
	sp->dist = malloc(sizeof(double) * count);
	if (!sp->dist)
		return (1);
	return (0);
}

static int	init_single_sprite(t_data *data, int idx, int type, double pos[2])
{
	t_sprite	*s;

	s = &data->sprites.arr[idx];
	s->x = pos[0] + 0.5;
	s->y = pos[1] + 0.5;
	s->type = type;
	s->active = 1;
	s->cur_frame = 0;
	if (type == SPRITE_COLLECTIBLE)
		return (generate_collect_frames(data, s));
	return (generate_exit_frames(data, s));
}

static int	fill_sprites(t_data *data)
{
	int		i;
	int		j;
	int		idx;
	double	pos[2];

	idx = 0;
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'C' || data->map[i][j] == 'X')
			{
				pos[0] = (double)j;
				pos[1] = (double)i;
				if (data->map[i][j] == 'C')
					init_single_sprite(data, idx++, SPRITE_COLLECTIBLE, pos);
				else
					init_single_sprite(data, idx++, SPRITE_EXIT, pos);
			}
		}
	}
	return (0);
}

int	init_sprites_from_map(t_data *data)
{
	int	n_collect;
	int	n_exit;
	int	total;

	total = count_sprites(data->map, &n_collect, &n_exit);
	data->sprites.count = total;
	data->total_collectibles = n_collect;
	data->sprites.collected = 0;
	data->sprites.anim_tick = 0;
	data->sprites.z_buffer = malloc(sizeof(double) * W_WIDTH);
	if (!data->sprites.z_buffer)
		return (1);
	if (total == 0)
		return (0);
	if (alloc_sprite_buffers(&data->sprites, total))
		return (1);
	return (fill_sprites(data));
}
