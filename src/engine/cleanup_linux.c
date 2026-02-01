/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:20:00 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/01 22:46:30 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

void	free_file_content(char **file_content)
{
	int	i;

	if (!file_content)
		return ;
	i = 0;
	while (file_content[i])
	{
		if (file_content[i])
			free(file_content[i]);
		i++;
	}
	free(file_content);
}

static void	destroy_image(void *mlx, t_img *img)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(mlx, img->img);
}

static void	free_texture_paths(t_texture *texture)
{
	int	i;

	if (texture->north.path)
		free(texture->north.path);
	if (texture->south.path)
		free(texture->south.path);
	if (texture->east.path)
		free(texture->east.path);
	if (texture->west.path)
		free(texture->west.path);
	if (texture->menu_start.path)
		free(texture->menu_start.path);
	if (texture->menu_exit.path)
		free(texture->menu_exit.path);
	i = -1;
	while (++i < WIN_FRAMES)
		if (texture->win[i].path)
			free(texture->win[i].path);
}

static void	cleanup_sprites(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->sprites.count)
	{
		j = 0;
		while (j < data->sprites.arr[i].frame_count)
			destroy_image(data->mlx, &data->sprites.arr[i].frames[j++]);
		i++;
	}
	free(data->sprites.arr);
	free(data->sprites.z_buffer);
	free(data->sprites.order);
	free(data->sprites.dist);
}

void	cleanup_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->mlx)
	{
		if (data->sprites.count > 0)
			cleanup_sprites(data);
		destroy_image(data->mlx, &data->texture.north);
		destroy_image(data->mlx, &data->texture.south);
		destroy_image(data->mlx, &data->texture.east);
		destroy_image(data->mlx, &data->texture.west);
		destroy_image(data->mlx, &data->texture.menu_start);
		destroy_image(data->mlx, &data->texture.menu_exit);
		i = -1;
		while (++i < WIN_FRAMES)
			destroy_image(data->mlx, &data->texture.win[i]);
		destroy_image(data->mlx, &data->render_img);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_texture_paths(&data->texture);
	free_file_content(data->file_content);
}
