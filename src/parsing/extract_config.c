/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:33 by ramahrez          #+#    #+#             */
/*   Updated: 2025/12/24 00:01:36 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parsing.h"

static int	extract_element(char **file_content, t_data *data)
{
	int	i;
	int	skip;

	i = 0;
	while (file_content[i])
	{
		skip = skip_isspace(file_content[i]);
		if (ft_strchr("NSWEA", file_content[i][skip]))
		{
			if (extract_texture(file_content[i] + skip, data))
				return (1);
		}
		if (ft_strchr("CF", file_content[i][skip]))
		{
			if (extract_color(file_content[i] + skip, data))
			{
				print_error("Error: invalid color");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	extract_config(char **file_content, t_data *data)
{
	if (extract_element(file_content, data))
		return (1);
	if (extract_map_data(file_content, data))
		return (1);
	extract_data_player(data->map, &data->player);
	if (verif_door(data->map))
		return (1);
	if (load_menu(data))
		return (1);
	return (0);
}
