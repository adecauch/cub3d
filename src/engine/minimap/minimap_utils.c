/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:30:51 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/02 16:00:15 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "minimap.h"
#include "mlx.h"
#include "parsing.h"
#include <math.h>

static void	draw_minimap_pixel_square(t_data *data, int scr_x, int scr_y,
		int color)
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
			if ((dx * dx) + (dy * dy) <= (data->minimap.radius
					* data->minimap.radius))
			{
				my_mlx_pixel_put(&data->render_img, scr_x + j, scr_y + i,
					color);
			}
			j++;
		}
		i++;
	}
}

static void	draw_minimap_tile(t_data *data, int tile[2], int scr_x, int scr_y)
{
	int		color;
	char	content;

	if (tile[1] < 0 || tile[1] >= data->minimap.map_height || tile[0] < 0
		|| tile[0] >= data->minimap.map_width)
		color = 0x222222;
	else
	{
		content = data->map[tile[1]][tile[0]];
		if (content == '1')
			color = data->minimap.color_wall;
		else if (content == 'C')
			color = data->minimap.color_floor;
		else if (content == 'X' && data->sprites.collected
			>= data->total_collectibles)
			color = 0x00FF00;
		else if (content == 'X')
			color = 0xFF0000;
		else if (content == '0' || ft_strchr("NSWE", content))
			color = data->minimap.color_floor;
		else
			color = data->minimap.color_wall;
	}
	draw_minimap_pixel_square(data, scr_x, scr_y, color);
}

void	draw_minimap_content(t_data *data)
{
	int	y;
	int	x;
	int	tile[2];
	int	range;

	range = (data->minimap.radius / data->minimap.size) + 1;
	y = -range;
	while (y <= range)
	{
		x = -range;
		while (x <= range)
		{
			tile[0] = (int)floor(data->player.x + x);
			tile[1] = (int)floor(data->player.y + y);
			draw_minimap_tile(data, tile,
				data->minimap.center_x + (tile[0] - data->player.x)
				* data->minimap.size,
				data->minimap.center_y + (tile[1] - data->player.y)
				* data->minimap.size);
			x++;
		}
		y++;
	}
}
