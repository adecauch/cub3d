/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:43:01 by hectordavro       #+#    #+#             */
/*   Updated: 2026/02/22 14:06:39 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	count_collectibles(char **map, int *total_collectibles)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				*total_collectibles += 1;
			x++;
		}
		y++;
	}
}

static void	get_map_height(char **map, int *height)
{
	*height = 0;
	if (!map)
		return ;
	while (map[*height])
		*height += 1;
}

static void	get_map_width(char **map, int *width)
{
	int	current_width;
	int	i;

	i = 0;
	if (!map)
	{
		*width = 0;
		return ;
	}
	while (map[i])
	{
		current_width = ft_strlen(map[i]);
		if (current_width > *width)
			*width = current_width;
		i++;
	}
}

int	get_map(char **file_content, t_data *data)
{
	int	i;

	i = 0;
	while (file_content[i])
	{
		if (file_content[i][skip_isspace(file_content[i])] == '1')
		{
			data->map = file_content + i;
			return (0);
		}
		i++;
	}
	return (print_error("Error: map missing"), 1);
}

int	extract_map_data(char **file_content, t_data *data)
{
	if (get_map(file_content, data))
		return (1);
	if (check_garbage_after_map(data->map))
		return (print_error("Error: invalid map"), 1);
	get_map_height((data->map), &data->minimap.map_height);
	get_map_width((data->map), &data->minimap.map_width);
	if (data->minimap.map_height > 8000 || data->minimap.map_height > 8000)
		return (print_error("Error: map too big"), 1);
	count_collectibles(data->map, &data->total_collectibles);
	return (0);
}
