/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:38:44 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/17 14:41:40 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	open_files(char *str)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(".cub", str + (ft_strlen(str) - 4), 4))
	{
		print_error("Error: extension not goot");
	}
	fd = open(str, O_RDONLY);
	if (fd < 1)
		print_error("Error: opening files");
	return (fd);
}

static void	clean_and_error(char ***content, int size, char *line, char *msg)
{
	int	i;

	i = size;
	while (i > 0)
		free((*content)[--i]);
	free(*content);
	free(line);
	print_error(msg);
}

static int	add_line_to_content(char ***content, char *line, int *size)
{
	char	**tmp;

	tmp = ft_realloc(*content, *size, *size + 2, sizeof(char *));
	if (!tmp)
	{
		clean_and_error(content, *size, line,
			"Error: allocation failed (realloc)\n");
		return (1);
	}
	*content = tmp;
	(*content)[*size] = ft_strdup(line);
	if (!(*content)[*size])
	{
		clean_and_error(content, *size, line,
			"Error: allocation failed (strdup)\n");
		return (1);
	}
	(*content)[*size + 1] = 0;
	(*size)++;
	free(line);
	return (0);
}

int	ft_read_file(int fd, char ***file_content)
{
	char	*str;
	int		size;
	int		ret;

	size = 0;
	if (fd < 0)
		return (1);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		ret = add_line_to_content(file_content, str, &size);
		if (ret != 0)
			return (1);
	}
	if (size == 0)
		return (-1);
	return (0);
}
