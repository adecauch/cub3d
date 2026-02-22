/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:20:00 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/22 19:45:56 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>
#include <unistd.h>

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
	{
		free(texture->win[i].path);
		free(texture->gameover[i].path);
	}
	if (texture->door.path)
		free(texture->door.path);
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
		{
			if (data->sprites.arr[i].frames[j].path)
				free(data->sprites.arr[i].frames[j].path);
			destroy_image(data->mlx, &data->sprites.arr[i].frames[j]);
			j++;
		}
		i++;
	}
	free(data->sprites.arr);
	free(data->sprites.z_buffer);
	free(data->sprites.order);
	free(data->sprites.dist);
}

void	cleanup_data(t_data *data)
{
	close(data->file_content_fd);
	free_texture_paths(&data->texture);
	free_file_content(data->file_content);
	if (data->map_backup)
	{
		free_file_content(data->map);
		free_file_content(data->map_backup);
	}
	if (!data->mlx)
		return ;
	cleanup_sprites(data);
	cleanup_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
