/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:30:27 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/08 23:56:48 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

static int	is_closed(char **map, int x, int y)
{
	if (x == 0 || map[y][x - 1] == ' ')
		return (0);
	if (map[y][x + 1] == '\0' || map[y][x + 1] == ' ')
		return (0);
	if (y == 0 || (int)ft_strlen(map[y - 1]) <= x || map[y - 1][x] == ' ')
		return (0);
	if (!map[y + 1] || (int)ft_strlen(map[y + 1]) <= x || map[y + 1][x] == ' ')
		return (0);
	return (1);
}

int	ft_check_map(char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			
			if (!ft_strchr("01NSEW ", map[i][j]) && map[i][j] != '\n')
				return (print_error("Error:Invalid char\n"), 1);
			if (ft_strchr("NSEW", map[i][j]))
				player++;
			if (ft_strchr("0NSEW", map[i][j]))
			{
				if (!is_closed(map, j, i))
					return (print_error("Error:Map not closed"), 1);
			}
		}
	}
	if (player != 1)
		return (print_error("Error\nWrong player count\n"), 1);
	return (0);
}
