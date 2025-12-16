/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:38:44 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/16 15:31:50 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "parsing.h"
#include <fcntl.h>
#include <stdio.h>

int	open_files(char *str)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(".cub", str + (ft_strlen(str) - 4), 4))
		print_error("Error: extension not goot");
	fd = open(str, O_RDONLY);
	if (fd < 1)
		print_error("Error: opening files");
	return (fd);
}

int	ft_read_file(int fd, char ***file_content)
{
	char	*str;
	char	**tmp;
	int		size;

	size = 0;
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		tmp = ft_realloc(*file_content, size, size + 2, sizeof(char *));
		if (!tmp)
		{
			while (size > 0)
				free((*file_content)[--size]);
			free(*file_content);
			free(str);
			print_error("Error: allocation failed\n");
			return (1);
		}
		*file_content = tmp;
		(*file_content)[size] = ft_strdup(str);
		free(str);
		if (!(*file_content)[size])
		{
			while (size > 0)
				free((*file_content)[--size]);
			free(*file_content);
			print_error("Error: strdup failed\n");
			return (1);
		}
		size++;
	}
	if (*file_content)
		(*file_content)[size] = 0;
	if (!file_content[0])
		return (-1);
	return (0);
}
