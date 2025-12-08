/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 05:45:58 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/05 05:45:59 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../so_long.h"

void	flood_fill_rec_col(char **map, t_parse parse, int x, int y)
{
	if (x >= (parse.size_line - 2) || y >= (parse.number_line - 1))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	map[y][x] = 'V';
	flood_fill_rec_col(map, parse, x + 1, y);
	flood_fill_rec_col(map, parse, x - 1, y);
	flood_fill_rec_col(map, parse, x, y + 1);
	flood_fill_rec_col(map, parse, x, y - 1);
}

void	flood_fill_rec_ex(char **map, t_parse parse, int x, int y)
{
	if (x >= (parse.size_line - 2) || y >= (parse.number_line - 1))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill_rec_ex(map, parse, x + 1, y);
	flood_fill_rec_ex(map, parse, x - 1, y);
	flood_fill_rec_ex(map, parse, x, y + 1);
	flood_fill_rec_ex(map, parse, x, y - 1);
}

char	check_access_col(char **map, t_parse parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse.number_line - 1)
	{
		j = 0;
		while (j < parse.size_line - 2)
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	check_access_ex(char **map, t_parse parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse.number_line - 1)
	{
		j = 0;
		while (j < parse.size_line - 2)
		{
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	flood_fill(char **map_one, char **map_two, t_parse parse)
{
	flood_fill_rec_col(map_one, parse, parse.start_x, parse.start_y);
	flood_fill_rec_ex(map_two, parse, parse.start_x, parse.start_y);
	if (check_access_col(map_one, parse) || check_access_ex(map_two, parse))
		return (1);
	return (0);
}
