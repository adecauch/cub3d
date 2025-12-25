/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:13:06 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/26 00:33:20 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	toggle_door(t_data *data)
{
	int		door_x;
	int		door_y;
	char	*door;

	door_x = (int)(data->player.x + data->player.dir_x * 1.0);
	door_y = (int)(data->player.y + data->player.dir_y * 1.0);
	if (door_x < 0 || door_y < 0)
		return ;
	if (!data->map[door_y] || !data->map[door_y][door_x])
		return ;
	door = &data->map[door_y][door_x];
	if (*door == 'D')
		*door = 'd';
	else if (*door == 'd')
		*door = 'D';
}
