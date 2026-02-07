/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:07:59 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/07 19:08:43 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"


static void	collect_item(t_data *data, int i)
{
	data->sprites.arr[i].active = 0;
	data->sprites.collected++;
	data->map[(int)(data->sprites.arr[i].y - 0.5)]
	[(int)(data->sprites.arr[i].x - 0.5)] = '0';
}

static void	try_collect(t_data *data, int i)
{
	double	dx;
	double	dy;

	dx = data->player.x - data->sprites.arr[i].x;
	dy = data->player.y - data->sprites.arr[i].y;
	if (dx * dx + dy * dy < PICKUP_DISTANCE * PICKUP_DISTANCE)
		collect_item(data, i);
}

void	check_collectible_pickup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sprites.count)
	{
		if (data->sprites.arr[i].active
			&& data->sprites.arr[i].type == SPRITE_COLLECTIBLE)
			try_collect(data, i);
		i++;
	}
}

void	check_exit_condition(t_data *data)
{
	int		i;
	double	dx;
	double	dy;

	if (data->sprites.collected < data->total_collectibles)
		return ;
	i = 0;
	while (i < data->sprites.count)
	{
		if (data->sprites.arr[i].type == SPRITE_EXIT)
		{
			dx = data->player.x - data->sprites.arr[i].x;
			dy = data->player.y - data->sprites.arr[i].y;
			if (dx * dx + dy * dy < PICKUP_DISTANCE * PICKUP_DISTANCE)
				data->state = WIN;
		}
		i++;
	}
}

void	verif_collectible(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->map[y][x] == 'C')
	{
		data->player.collected++;
		data->map[y][x] = '0';
	}
	if (data->map[y][x] == 'T'
		&& (data->total_collectibles == data->player.collected))
		close_game(data);
}
