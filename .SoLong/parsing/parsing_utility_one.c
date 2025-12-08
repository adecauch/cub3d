/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utility_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:12:42 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/05 07:01:18 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "parsing.h"

int	number_line(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error Map : Could not open map file.\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr("Error Map : Map empty.\n");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	init_parse(t_parse *parse)
{
	parse->collectible = 0;
	parse->exit = 0;
	parse->start = 0;
	parse->intruder = 0;
	parse->start_x = 0;
	parse->start_y = 0;
	parse->size_line = 0;
	parse->number_line = 0;
}

void	exit_parse(char *error_message, char **map)
{
	free_map(map);
	ft_putstr(error_message);
	exit(EXIT_FAILURE);
}

char	**copy_map(char **map, int size)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strndup(map[i], ft_strlen(map[i]));
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
