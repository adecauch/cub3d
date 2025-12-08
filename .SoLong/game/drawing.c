/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:00:50 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/06 03:08:55 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_image(void *mlx, t_image *image)
{
	int	raf;

	raf = 0;
	image->wall = mlx_xpm_file_to_image(mlx, "xpm/wall.xpm", &raf, &raf);
	image->floor = mlx_xpm_file_to_image(mlx, "xpm/floor.xpm", &raf, &raf);
	image->exit = mlx_xpm_file_to_image(mlx, "xpm/exit1.xpm", &raf, &raf);
	image->exit2 = mlx_xpm_file_to_image(mlx, "xpm/exit2.xpm", &raf, &raf);
	image->collect = mlx_xpm_file_to_image(mlx, "xpm/burger.xpm", &raf, &raf);
	image->cartman = mlx_xpm_file_to_image(mlx, "xpm/cartman.xpm", &raf, &raf);
}

void	draw_map(void *mlx, void *win, char **map, t_image image)
{
	int		i;
	int		x;
	int		y;
	t_draw	draw;

	x = 0;
	y = 0;
	i = 0;
	draw.mlx = mlx;
	draw.win = win;
	draw.image = image;
	while (map[i])
	{
		draw.y = y;
		draw_line(&draw, map[i], &x);
		x = 0;
		y += 64;
		i++;
	}
}
