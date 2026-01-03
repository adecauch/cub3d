/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:07:00 by hectordavro       #+#    #+#             */
/*   Updated: 2026/01/03 16:01:44 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mlx.h"
#include "parsing.h"

static void	init_player(t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->speed = 0.0;
	player->health = 100;
	player->collected = 0;
	player->damage = 10;
}

static void	init_texture_menu(t_texture *texture)
{
	texture->menu_exit.path = ft_strdup("data/texture/menu_exit.xpm");
	texture->menu_start.path = ft_strdup("data/texture/menu_start.xpm");
}

void	init_minimap(t_minimap *mm)
{
	mm->radius = 100;
	mm->size = 8;
	mm->center_x = 10 + mm->radius;
	mm->center_y = 10 + mm->radius;
	mm->color_wall = 0x000000;
	mm->color_floor = 0x555555;
	mm->color_player = 0xFF0000;
	mm->color_collectible = 0xffde21;
	mm->margin = 10;
	mm->map_height = 0;
	mm->map_width = 0;
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->map = NULL;
	init_player(&data->player);
	data->mlx = mlx_init();
	data->total_collectibles = 0;
	init_minimap(&data->minimap);
	init_texture_menu(&data->texture);
}
