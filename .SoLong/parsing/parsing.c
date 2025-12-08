/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:21:31 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/23 13:21:56 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "parsing.h"

char	**create_map(char *file_name, t_parse *parse)
{
	int		fd;
	int		i;
	char	*free_gnl;
	char	**map;

	i = 0;
	parse->number_line = number_line(file_name);
	fd = open(file_name, O_RDONLY);
	map = malloc((parse->number_line + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < parse->number_line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	free_gnl = get_next_line(fd);
	free(free_gnl);
	close(fd);
	parse->size_line = ft_strlen(map[0]);
	return (map);
}

void	first_parse(char **map, t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				parse->collectible++;
			else if (map[i][j] == 'E')
				parse->exit++;
			else if (map[i][j] == 'P')
			{
				parse->start++;
				parse->start_x = j;
				parse->start_y = i;
			}
			else if (map[i][j] != '\n' && map[i][j] != '0' && map [i][j] != '1')
				parse->intruder++;
			j++;
		}
		i++;
	}
}

void	second_parse(char **map, t_parse *parse)
{
	int		i;

	i = 0;
	parse->size_line = check_only_one(map[i], map);
	i++;
	while (i < (parse->number_line - 1))
	{
		if (check_one_border(map[i], map) != parse->size_line)
			exit_parse("Error Map : map is not a rectangle\n", map);
		i++;
	}
	if (check_only_one(map[i], map) != parse->size_line)
		exit_parse("Error Map : map is not a rectangle\n", map);
}

void	exit_all_map(char **map, char **cp_map_one, char **cp_map_two)
{
	free_map(cp_map_one);
	free_map(cp_map_two);
	exit_parse("Error Map : Unreachable element\n", map);
}

char	**create_parse_map(char *file_name, int *x, int *y)
{
	char	**map;
	char	**cp_map_one;
	char	**cp_map_two;
	t_parse	parse;

	init_parse(&parse);
	if (!file_name)
		map = create_map("default_map.ber", &parse);
	else
		map = create_map(file_name, &parse);
	check_size_map(parse, map);
	first_parse(map, &parse);
	check_parse(parse, map);
	second_parse(map, &parse);
	cp_map_one = copy_map(map, parse.number_line);
	cp_map_two = copy_map(map, parse.number_line);
	if (flood_fill(cp_map_one, cp_map_two, parse))
		exit_all_map(map, cp_map_one, cp_map_two);
	*x = parse.size_line - 1;
	*y = parse.number_line;
	free_map(cp_map_one);
	free_map(cp_map_two);
	return (map);
}
