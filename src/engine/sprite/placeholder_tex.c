/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:45:24 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 16:01:07 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	create_runtime_img(t_data *data, t_img *img, int size)
{
	img->width = size;
	img->height = size;
	img->path = NULL;
	img->img = mlx_new_image(data->mlx, size, size);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	return (0);
}

void	fill_img_diamond(t_img *img, int color)
{
	int	x;
	int	y;
	int	c;

	c = img->width / 2;
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			if (abs(x - c) + abs(y - c) < c)
				my_mlx_pixel_put(img, x, y, color);
			else
				my_mlx_pixel_put(img, x, y, 0x000000);
		}
	}
}

int	try_load_xpm(t_data *data, t_img *img, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	img->path = ft_strdup(path);
	if (load_texture(img, data->mlx))
	{
		free(img->path);
		img->path = NULL;
		return (1);
	}
	return (0);
}

int	generate_collect_frames(t_data *data, t_sprite *sprite)
{
	sprite->frame_count = 2;
	if (!try_load_xpm(data, &sprite->frames[0],
			"data/texture/collectible_1.xpm")
		&& !try_load_xpm(data, &sprite->frames[1],
			"data/texture/collectible_2.xpm"))
		return (0);
	if (create_runtime_img(data, &sprite->frames[0], SPRITE_TEX_SIZE))
		return (1);
	fill_img_diamond(&sprite->frames[0], 0xFFD700);
	if (create_runtime_img(data, &sprite->frames[1], SPRITE_TEX_SIZE))
		return (1);
	fill_img_diamond(&sprite->frames[1], 0xCCA300);
	return (0);
}

int	generate_exit_frames(t_data *data, t_sprite *sprite)
{
	sprite->frame_count = 2;
	if (!try_load_xpm(data, &sprite->frames[0],
			"data/texture/exit_closed.xpm")
		&& !try_load_xpm(data, &sprite->frames[1],
			"data/texture/exit_open.xpm"))
		return (0);
	if (create_runtime_img(data, &sprite->frames[0], SPRITE_TEX_SIZE))
		return (1);
	fill_img_diamond(&sprite->frames[0], 0xFF0000);
	if (create_runtime_img(data, &sprite->frames[1], SPRITE_TEX_SIZE))
		return (1);
	fill_img_diamond(&sprite->frames[1], 0x00FF00);
	return (0);
}
