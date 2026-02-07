/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:57:16 by hectordavro       #+#    #+#             */
/*   Updated: 2026/01/03 00:44:47 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parsing.h"
#include <stdio.h>
#include <unistd.h>

int	ft_parsing(char *file_name, t_data *data)
{
	data->file_content = NULL;
	if (ft_read_file(open_files(file_name), &data->file_content))
		return (1);
	if (verif_textures(data->file_content))
		return (1);
	if (extract_config(data->file_content, data))
		return (1);
	return (0);
}
