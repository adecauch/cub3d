/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_config_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:52:39 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/21 20:31:42 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parsing.h"

int	load_texture(t_img *texture, void *mlx)
{
	texture->img = mlx_xpm_file_to_image(mlx, texture->path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		print_error("Error: load texture path:");
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

static int	extract_texture_utils(char *texture, t_data *data)
{
	if (!ft_strncmp(texture, "WE", 2))
	{
		data->texture.west.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		if (load_texture(&data->texture.west, data->mlx))
			return (1);
	}
	if (!ft_strncmp(texture, "EA", 2))
	{
		data->texture.east.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		if (load_texture(&data->texture.east, data->mlx))
			return (1);
	}
	return (0);
}

int	extract_texture(char *texture, t_data *data)
{
	if (!ft_strncmp(texture, "NO", 2))
	{
		data->texture.north.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		if (load_texture(&data->texture.north, data->mlx))
			return (1);
	}
	else if (!ft_strncmp(texture, "SO", 2))
	{
		data->texture.south.path = ft_strtrim(texture + 2 + skip_isspace(texture
					+ 2), "\n");
		if (load_texture(&data->texture.south, data->mlx))
			return (1);
	}
	else
		return (extract_texture_utils(texture, data));
	return (0);
}

int	load_menu(t_data *data)
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
	return (0);
}
