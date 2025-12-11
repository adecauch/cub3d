/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:30:00 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/11 13:39:48 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

void	rotate_player(t_player *player, double rotation_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation_speed)
		- player->dir_y * sin(rotation_speed);
	player->dir_y = old_dir_x * sin(rotation_speed)
		+ player->dir_y * cos(rotation_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation_speed)
		- player->plane_y * sin(rotation_speed);
	player->plane_y = old_plane_x * sin(rotation_speed)
		+ player->plane_y * cos(rotation_speed);
}

static int	can_move_to(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_x < 0 || map_y < 0)
		return (0);
	if (!data->map[map_y] || !data->map[map_y][map_x])
		return (0);
	if (data->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	move_player(t_data *data, double direction)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.1 * direction;
	new_x = data->player.x + data->player.dir_x * move_speed;
	new_y = data->player.y + data->player.dir_y * move_speed;
	if (can_move_to(data, new_x, data->player.y))
		data->player.x = new_x;
	if (can_move_to(data, data->player.x, new_y))
		data->player.y = new_y;
}

void	strafe_player(t_data *data, double direction)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.1 * direction;
	new_x = data->player.x + data->player.plane_x * move_speed;
	new_y = data->player.y + data->player.plane_y * move_speed;
	if (can_move_to(data, new_x, data->player.y))
		data->player.x = new_x;
	if (can_move_to(data, data->player.x, new_y))
		data->player.y = new_y;
}
