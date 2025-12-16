/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:43:01 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/16 15:37:47 by ramahrez         ###   ########.fr       */
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

void	extract_data_player(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				setup_player(j, i, map[i][j], player);
			j++;
		}
		i++;
	}
}

int	extract_map(char **file_content, t_data *data)
{
	int	i;

	i = 0;
	while (file_content[i])
	{
		if (file_content[i][skip_isspace(file_content[i])] == '1')
		{
			data->map = file_content + i;
			break ;
		}
		i++;
	}
	return (0);
}
