/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:03:10 by ramahrez          #+#    #+#             */
/*   Updated: 2025/12/18 12:04:38 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "minimap.h"
#include "mlx.h"
#include <math.h>

void	draw_minimap_circle(t_data *data)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	y = data->minimap.center_y - data->minimap.radius;
	while (y <= data->minimap.center_y + data->minimap.radius)
	{
		x = data->minimap.center_x - data->minimap.radius;
		while (x <= data->minimap.center_x + data->minimap.radius)
		{
			dx = x - data->minimap.center_x;
			dy = y - data->minimap.center_y;
			if ((dx * dx) + (dy * dy) <= (data->minimap.radius
					* data->minimap.radius))
			{
				if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
					my_mlx_pixel_put(&data->render_img, x, y,
						data->minimap.color_wall);
			}
			x++;
		}
		y++;
	}
}

void	draw_player_dot(t_data *data)
{
	const int	dot_size = 4;
	int			i;
	int			j;

	i = -(dot_size / 2);
	while (i < (dot_size / 2))
	{
		j = -(dot_size / 2);
		while (j < (dot_size / 2))
		{
			my_mlx_pixel_put(&data->render_img, data->minimap.center_x + j,
				data->minimap.center_y + i, data->minimap.color_player);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_data *data)
{
	draw_minimap_circle(data);
	draw_minimap_content(data);
	draw_player_dot(data);
}
