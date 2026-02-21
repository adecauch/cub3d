/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:59:15 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/21 20:14:08 by ramahrez         ###   ########.fr       */
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

static int	load_win_frames(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIN_FRAMES)
	{
		if (load_texture(&data->texture.win[i], data->mlx))
		{
			print_error("Error: load win texture");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	load_gameover_frames(t_data *data)
{
	int	i;

	i = 0;
	while (i < GAMEOVER_FRAMES)
	{
		if (load_texture(&data->texture.gameover[i], data->mlx))
		{
			print_error("Error: load gameover texture");
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
	if (load_win_frames(data))
		return (1);
	return (load_gameover_frames(data));
}

int	extract_config(char **file_content, t_data *data)
{
	if (extract_element(file_content, data))
		return (1);
	if (extract_map_data(file_content, data))
		return (1);
	if (extract_data_player(data->map, &data->player))
		return(1);
	if (verif_door(data->map))
			return (1);
	if (ft_check_path_and_collectibles(data->map, data))
		return (1);
	if (load_bonus(data))
		return (1);
	return (0);
}
