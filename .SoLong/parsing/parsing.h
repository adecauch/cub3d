/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:10:24 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/27 23:10:27 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct parse
{
	char	collectible;
	char	exit;
	char	start;
	char	intruder;
	int		start_x;
	int		start_y;
	int		size_line;
	int		number_line;
}			t_parse;

void	init_parse(t_parse *parse);
int		number_line(char *file_name);
void	check_size_map(t_parse parse, char **map);
int		check_only_one(char *str, char **map);
int		check_one_border(char *str, char **map);
void	check_parse(t_parse parse, char **map);
char	**copy_map(char **map, int size);
void	exit_parse(char *error_message, char **map);
char	flood_fill(char **map_one, char **map_two, t_parse parse);

#endif
