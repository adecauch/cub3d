/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:46:44 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/01 22:46:46 by adecauch         ###   ########.fr       */
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

	if (data->sprites.collected < data->sprites.total_collect)
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
