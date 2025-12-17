/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:30:51 by ramahrez          #+#    #+#             */
/*   Updated: 2025/12/17 22:56:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minimap.h"
#include "game.h"
#include "mlx.h"

static void	draw_minimap_pixel_square(t_data *data, int scr_x, int scr_y, int color)
{
    int	i;
    int	j;
    int	dx;
    int	dy;
    
    i = 0;
    while (i < data->minimap.size)
    {
        j = 0;
        while (j < data->minimap.size)
        {
            dx = (scr_x + j) - data->minimap.center_x;
            dy = (scr_y + i) - data->minimap.center_y;
            
            if ((dx * dx) + (dy * dy) <= (data->minimap.radius * data->minimap.radius))
            {
                 my_mlx_pixel_put(&data->render_img, scr_x + j, scr_y + i, color);
            }
            j++;
        }
        i++;
    }
}

void draw_minimap_tile(t_data *data, int m_x, int m_y, int scr_x, int scr_y)
{
    int         color;
    char        content;
    
   
    if (m_y < 0 || m_y >= data->minimap.map_height || m_x < 0 || m_x >= data->minimap.map_width)
        color = 0x222222; 
    else 
    {
        content = data->map[m_y][m_x];
        if (content == '1')
            color = data->minimap.color_wall;
        else if (content == '0' || ft_strchr("NSWE", content)) 
            color = data->minimap.color_floor;
        else
            color = 0x00FF00;
    }
    draw_minimap_pixel_square(data, scr_x, scr_y, color);
}


void draw_minimap_content(t_data *data)
{
    int             y;
    int             x;
    int             map_grid_x;
    int             map_grid_y;
    const int       range = (data->minimap.radius / data->minimap.size) + 1; // Déclaration 5

    y = -range;
    while (y <= range)
    {
        x = -range;
        while (x <= range)
        {
            map_grid_x = (int)floor(data->player.x + x);
            map_grid_y = (int)floor(data->player.y + y);
            draw_minimap_tile(data, map_grid_x, map_grid_y, 
                data->minimap.center_x + (map_grid_x - data->player.x) * data->minimap.size,
                data->minimap.center_y + (map_grid_y - data->player.y) * data->minimap.size);
            x++;
        }
        y++;
    }
}
