/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:23:10 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/18 15:19:16 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>

static int	get_color_component(char **line_ptr, int *component_out)
{
	long long	value;
	char		*start_ptr;

	start_ptr = *line_ptr;
	if (!ft_isdigit(*start_ptr))
		return (1);
	value = ft_atoi(*line_ptr);
	while (ft_isdigit(**line_ptr))
		(*line_ptr)++;
	if (*line_ptr == start_ptr)
		return (1);
	if (value < 0 || value > 255)
		return (1);
	*component_out = (int)value;
	return (0);
}

static int	parse_next_component(char **line_ptr, int *component_out)
{
	if (get_color_component(line_ptr, component_out))
		return (1);
	*line_ptr = *line_ptr + skip_isspace(*line_ptr);
	if (**line_ptr != ',')
		return (print_error("Error: color invalid"), 1);
	(*line_ptr)++;
	return (0);
}

static int	parse_rgb_line(char *line, int *color_out)
{
	int	r;
	int	g;
	int	b;

	b = 0;
	if (!line)
		return (1);
	line = line + skip_isspace(line);
	if (parse_next_component(&line, &r))
		return (1);
	line = line + skip_isspace(line);
	if (parse_next_component(&line, &g))
		return (1);
	line = line + skip_isspace(line);
	if (get_color_component(&line, &b))
		return (1);
	line = line + skip_isspace(line);
	if (*line != '\0')
		return (1);
	*color_out = (r << 16) | (g << 8) | b;
	return (0);
}

int	extract_color(char *color, t_data *data)
{
	if (*color == 'C')
	{
		if (parse_rgb_line((color + 1 + skip_isspace(color + 1)),
				&data->texture.ceil_color))
			return (1);
	}
	if (*color == 'F')
	{
		if (parse_rgb_line((color + 1 + skip_isspace(color + 1)),
				&data->texture.floor_color))
			return (1);
	}
	return (0);
}
