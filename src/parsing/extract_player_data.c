/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_player_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:51:24 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/09 02:44:17 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	setup_direction_two(char direction, t_player *player)
{
	if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

static void	setup_diection(char direction, t_player *player)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	setup_direction_two(direction, player);
}

static void	setup_player(int x, int y, char direction, t_player *player)
{
	player->x = x + 0.5;
	player->y = y + 0.5;
	setup_diection(direction, player);
}

int	extract_data_player(char **map, t_player *player)
{
	int	i;
	int	j;
	int error;
	
	error = 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				setup_player(j, i, map[i][j], player);
				error = 0;
			}
			j++;
		}
		i++;
	}
	if (error)
		return (print_error("Error: not player"), 1);
	return (0);
}
