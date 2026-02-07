/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:00:13 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/07 19:00:16 by ramahrez         ###   ########.fr       */
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

static void	init_bonus_texture(t_texture *texture)
{
	texture->menu_exit.path = ft_strdup("data/texture/menu_exit.xpm");
	texture->menu_start.path = ft_strdup("data/texture/menu_start.xpm");
	texture->door.path = ft_strdup("data/texture/door.xpm");
	texture->win[0].path = ft_strdup("data/texture/win_1.xpm");
	texture->win[1].path = ft_strdup("data/texture/win_2.xpm");
	texture->win[2].path = ft_strdup("data/texture/win_3.xpm");
	texture->win[3].path = ft_strdup("data/texture/win_4.xpm");
	texture->win_tick = 0;
	texture->gameover[0].path = ft_strdup("data/texture/gameover_1.xpm");
	texture->gameover[1].path = ft_strdup("data/texture/gameover_2.xpm");
	texture->gameover[2].path = ft_strdup("data/texture/gameover_3.xpm");
	texture->gameover[3].path = ft_strdup("data/texture/gameover_4.xpm");
	texture->gameover_tick = 0;
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
	mm->color_exit = 0x0000ff;
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
	init_bonus_texture(&data->texture);
}
