/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:08:03 by ramahrez          #+#    #+#             */
/*   Updated: 2026/01/03 16:00:18 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

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
}
