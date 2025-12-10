/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:43:01 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/10 13:49:51 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

// static void

static void setup_diection(char direction, t_player *player)
{
    if(direction == 'N')
    {
        player->dir_x = 0;
        player->dir_y = -1;
    }
    if(direction == 'S')
    {
        player->dir_x = 0;
        player->dir_y = 1;
    }
    if(direction == 'E')
    {
        player->dir_x = 1;
        player->dir_y = 0;
    }
    if(direction == 'W')
    {
        player->dir_x = -1;
        player->dir_y = 0;
    }
}

static void setup_player(int x, int y, char direction, t_player *player)
{
    player->x  = x;
    player->y = y;
    setup_diection(direction, player);
}

void extract_data_player(char **map, t_player *player)
{
    int i = 0;
    int j;

    while(map[i])
    {
        j = 0;
        while(map[j])
        {
            if(ft_strchr("NSEW", map[i][j]))
                setup_player(j, i, map[i][j], player);
            j++;
        }
        i++;
    }
}

int extract_map(char **file_content, t_data *data)
{
    int i = 0;
    
    while(file_content[i])
    {
        if(file_content[i][skip_isspace(file_content[i])] == '1')
        {
            data->map = file_content + i;
            break;
        }
        i++;
    }
    return(0);
}
