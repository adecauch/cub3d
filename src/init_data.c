/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:07:00 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/09 00:37:27 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "cub_3d.h"

static void init_enemy_list(t_enemy_node **list)
{
    *list = NULL;
}

static void init_player(t_player *player)
{
    player->x = 0.0;
    player->y = 0.0;
    player->dir_x = 0.0;
    player->dir_y = 0.0;
    player->speed = 0.0;
    player->health = 100;
    player->damage = 10;
}


void init_data(t_data *data)
{
    ft_memset(data, 0, sizeof(t_data)); 
    init_player(&data->player);
    init_enemy_list(&data->enemy_list);
}