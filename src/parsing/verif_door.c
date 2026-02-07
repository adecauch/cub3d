/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:04:01 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/07 21:02:59 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_floor(char c)
{
	return (c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == 'C' || c == 'X');
}

static int	validate_door(char **map, int y, int x)
{
	if (x == 0 || y == 0 || !map[y + 1] || !map[y][x + 1])
		return (1);
	if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
	{
		if (is_floor(map[y - 1][x]) && is_floor(map[y + 1][x]))
			return (0);
	}
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
	{
		if (is_floor(map[y][x - 1]) && is_floor(map[y][x + 1]))
			return (0);
	}
	return (1);
}

int	verif_door(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
			{
				if (validate_door(map, y, x))
					return (print_error("Error: Door not valid"), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
