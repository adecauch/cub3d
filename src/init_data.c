/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:07:00 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/16 15:34:34 by ramahrez         ###   ########.fr       */
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
	player->damage = 10;
}

static void	init_texture_menu(t_texture *texture)
{
	texture->menu_exit.path = "data/texture/menu_exit.xpm";
	texture->menu_start.path = "data/texture/menu_start.xpm";
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->map = NULL;
	init_player(&data->player);
	data->mlx = mlx_init();
	init_texture_menu(&data->texture);
}
