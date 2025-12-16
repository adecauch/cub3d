/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:32:20 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/16 15:34:10 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_texture_line(char *s)
{
	if (!ft_strncmp(s, "NO", 2))
		return (1);
	if (!ft_strncmp(s, "SO", 2))
		return (1);
	if (!ft_strncmp(s, "WE", 2))
		return (1);
	if (!ft_strncmp(s, "EA", 2))
		return (1);
	if (!ft_strncmp(s, "F", 1))
		return (1);
	if (!ft_strncmp(s, "C", 1))
		return (1);
	return (0);
}

static int	verif_textures(char **files)
{
	int	i;
	int	skip;
	int	count;

	i = 0;
	count = 0;
	while (files[i])
	{
		skip = skip_isspace(files[i]);
		if (is_texture_line(files[i] + skip))
			count++;
		else if (!ft_strncmp(files[i] + skip, "1", 1))
			break ;
		else if (!ft_strncmp(files[i] + skip, "\0", 1))
			;
		else
			return (1);
		i++;
	}
	if (count != 6)
		return (print_error("Error:missing or too many textures\n"), 1);
	return (ft_check_map(files + i));
}

int	verif_files(char **files)
{
	if (verif_textures(files))
		return (1);
	return (0);
}
