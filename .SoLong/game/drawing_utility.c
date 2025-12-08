/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:00:50 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/06 03:08:55 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_wall_floor(t_draw draw)
{
	if (draw.c == '1')
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.wall,
			draw.x, draw.y);
	else if (draw.c == '0')
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.floor,
			draw.x, draw.y);
}

void	draw_player_collect(t_draw draw)
{
	if (draw.c == 'P')
	{
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.floor,
			draw.x, draw.y);
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.cartman,
			draw.x, draw.y);
	}
	else if (draw.c == 'C')
	{
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.floor,
			draw.x, draw.y);
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.collect,
			draw.x, draw.y);
	}
}

void	draw_exit(t_draw draw)
{
	if (draw.c == 'E')
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.exit,
			draw.x, draw.y);
	else if (draw.c == 'e')
		mlx_put_image_to_window(draw.mlx, draw.win, draw.image.exit2,
			draw.x, draw.y);
}

void	draw_item(t_draw draw)
{
	draw_wall_floor(draw);
	draw_player_collect(draw);
	draw_exit(draw);
}

void	draw_line(t_draw *draw, char *line, int *x)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		draw->c = line[j];
		draw->x = *x;
		draw_item(*draw);
		j++;
		*x += 64;
	}
}
