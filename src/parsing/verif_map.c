/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:02:08 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/22 16:26:46 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
#include "game.h"
#include "parsing.h"
#include <stdio.h>

static int	check_char_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_strchr("NSEWCDXs01 ", map[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **map_copy, int x, int y, t_check *info)
{
	if (info->error == 1)
		return ;
	if (y < 0 || x < 0 || !map_copy[y])
	{
		info->error = 1;
		return ;
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == ' ' || map_copy[y][x] == '\t' || map_copy[y][x] == 0
		|| map_copy[y][x] == '\n')
	{
		info->error = 1;
		return ;
	}
	if (map_copy[y][x] == 'X')
		info->exit_found = 1;
	if (map_copy[y][x] == 'C')
		info->collectibles_found++;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, info);
	flood_fill(map_copy, x - 1, y, info);
	flood_fill(map_copy, x, y + 1, info);
	flood_fill(map_copy, x, y - 1, info);
}

int	check_garbage_after_map(char **map)
{
	int	i;
	int	map_ended;

	i = 0;
	map_ended = 0;
	while (map[i])
	{
		if (map[i][skip_isspace(map[i])] == '\0')
			map_ended = 1;
		else if (map_ended == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	check_player(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (1);
	return (0);
}

int	ft_check_path_and_collectibles(char **map, t_data *data)
{
	char	**map_copy;
	t_check	check_info;

	check_info.collectibles_found = 0;
	check_info.error = 0;
	check_info.exit_found = 0;
	if (check_char_map(map))
		return (print_error("char invalid in the map"), 1);
	if (check_player(map))
		return (print_error("Error: many players"), 1);
	map_copy = ft_tabdup(map);
	if (!map_copy)
		return (print_error("Malloc error"), 1);
	flood_fill(map_copy, data->player.x, data->player.y, &check_info);
	free_file_content(map_copy);
	if (check_info.error == 1)
		return (print_error("Error: Map not closed (hole found)"), 1);
	if (check_info.collectibles_found != data->total_collectibles)
		return (print_error("Error: Unreachable collectible"), 1);
	return (0);
}
