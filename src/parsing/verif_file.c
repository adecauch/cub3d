/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:32:20 by hectordavro       #+#    #+#             */
/*   Updated: 2026/02/21 18:09:49 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_texture_index(char *s)
{
	if (!ft_strncmp(s, "NO ", 3))
		return (0);
	if (!ft_strncmp(s, "SO ", 3))
		return (1);
	if (!ft_strncmp(s, "WE ", 3))
		return (2);
	if (!ft_strncmp(s, "EA ", 3))
		return (3);
	if (!ft_strncmp(s, "F ", 2))
		return (4);
	if (!ft_strncmp(s, "C ", 2))
		return (5);
	return (-1);
}

static int	is_map_start(char *line)
{
	int	i;

	i = skip_isspace(line);
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

static int	process_texture_line(char *line, int *check, int *count)
{
	int	tex_idx;
	int	skip;

	skip = skip_isspace(line);
	if (line[skip] == '\0')
		return (0);
	tex_idx = get_texture_index(line + skip);
	if (tex_idx != -1)
	{
		if (check[tex_idx]++ > 0)
			return (print_error("Error: Duplicate texture"), -1);
		(*count)++;
		return (0);
	}
	if (is_map_start(line))
		return (1);
	return (print_error("Error: Invalid line in file"), -1);
}

int	verif_textures(char **files)
{
	int	i;
	int	count;
	int	check[6];
	int	status;

	i = -1;
	while (++i < 6)
		check[i] = 0;
	i = 0;
	count = 0;
	while (files[i])
	{
		status = process_texture_line(files[i], check, &count);
		if (status == 1)
			break ;
		if (status == -1)
			return (1);
		i++;
	}
	if (count != 6)
		return (print_error("Error: Missing textures"), 1);
	return (0);
}
