/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:30:27 by hectordavro       #+#    #+#             */
/*   Updated: 2026/01/08 13:42:11 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "game.h"
#include <stdio.h>
#include "flood_fill.h"

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
			if (!(ft_strchr("NSEWCDT01 ", map[i][j])))
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
	if (map_copy[y][x] == ' ' || map_copy[y][x] == '\t' ||
			map_copy[y][x] == 0 || map_copy[y][x] == '\n')
	{
		info->error = 1;
		return ;
	}
	if (map_copy[y][x] == 'T')
		info->exit_found = 1;
	if (map_copy[y][x] == 'C')
		info->collectibles_found++;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, info);
	flood_fill(map_copy, x - 1, y, info);
	flood_fill(map_copy, x, y + 1, info);
	flood_fill(map_copy, x, y - 1, info);
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
	map_copy = ft_tabdup(map);
	if (!map_copy)
		return (print_error("Malloc error"), 1);
	flood_fill(map_copy, data->player.x, data->player.y, &check_info);
	free_file_content(map_copy);
	if (check_info.error == 1)
		return (print_error("Error: Map not closed (hole found)"), 1);
	if (check_info.collectibles_found != data->total_collectibles)
		return (print_error("Error: Unreachable collectible"), 1);
	if (!check_info.exit_found)
		return (print_error("Error: exit not accecible"), 1);
	return (0);
}
