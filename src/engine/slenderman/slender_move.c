/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slender_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:00:47 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 16:00:50 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

static int	can_slender_move(t_data *data, double nx, double ny)
{
	int	mx;
	int	my;

	mx = (int)nx;
	my = (int)ny;
	if (mx < 0 || my < 0)
		return (0);
	if (!data->map[my] || !data->map[my][mx])
		return (0);
	if (data->map[my][mx] == '1' || data->map[my][mx] == 'D')
		return (0);
	return (1);
}

static double	get_slender_speed(t_data *data)
{
	double	ratio;

	if (data->total_collectibles == 0)
		return (SLENDER_BASE_SPEED);
	ratio = (double)data->sprites.collected
		/ (double)data->total_collectibles;
	return (SLENDER_BASE_SPEED + ratio
		* (SLENDER_MAX_SPEED - SLENDER_BASE_SPEED));
}

static void	move_toward_player(t_data *data)
{
	double	dx;
	double	dy;
	double	len;
	double	spd;

	dx = data->player.x - data->slender.x;
	dy = data->player.y - data->slender.y;
	len = sqrt(dx * dx + dy * dy);
	if (len < 0.001)
		return ;
	dx /= len;
	dy /= len;
	spd = get_slender_speed(data);
	if (can_slender_move(data, data->slender.x + dx * spd, data->slender.y))
		data->slender.x += dx * spd;
	if (can_slender_move(data, data->slender.x, data->slender.y + dy * spd))
		data->slender.y += dy * spd;
}

void	update_slenderman(t_data *data)
{
	if (!data->slender.active)
		return ;
	move_toward_player(data);
	update_slender_anim(data);
	check_slender_catch(data);
}
