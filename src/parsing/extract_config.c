/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:33 by ramahrez          #+#    #+#             */
/*   Updated: 2025/12/26 15:26:42 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parsing.h"

static int	load_texture(t_img *texture, void *mlx)
{
	texture->img = mlx_xpm_file_to_image(mlx, texture->path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		print_error("Error: load texture path:");
		print_error(texture->path);
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->addr)
	{
		print_error("Error: Could not retrieve texture pixel address.\n");
		return (1);
	}
	return (0);
}

static int	extract_texture(char *texture, t_data *data)
{
	if (!ft_strncmp(texture, "NO", 2))
	{
		data->texture.north.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		load_texture(&data->texture.north, data->mlx);
	}
	if (!ft_strncmp(texture, "SO", 2))
	{
		data->texture.south.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		load_texture(&data->texture.south, data->mlx);
	}
	if (!ft_strncmp(texture, "WE", 2))
	{
		data->texture.west.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		load_texture(&data->texture.west, data->mlx);
	}
	if (!ft_strncmp(texture, "EA", 2))
	{
		data->texture.east.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		load_texture(&data->texture.east, data->mlx);
	}
	return (0);
}

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
				return (1);
		}
		i++;
	}
	return (0);
}

static int	load_bonus(t_data *data)
{
	if (load_texture(&data->texture.menu_exit, data->mlx))
	{
		print_error("Error: load texture path: data/texture/menu_exit.xpm");
		return (1);
	}
	if (load_texture(&data->texture.menu_start, data->mlx))
	{
		print_error("Error: load texture path: data/texture/menu_start.xpm");
		return (1);
	}
	if (load_texture(&data->texture.door, data->mlx))
	{
		print_error("Error: load texture path: data/texture/door.xpm");
		return (1);
	}
	return (0);
}

int	extract_config(char **file_content, t_data *data)
{
	if (extract_element(file_content, data))
		return (1);
	if (extract_map(file_content, data))
		return (1);
	extract_data_player(data->map, &data->player);
	if (load_bonus(data))
		return (1);
	return (0);
}
