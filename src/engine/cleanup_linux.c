/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:20:00 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/17 16:37:20 by adecauch         ###   ########.fr       */
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
}

void	cleanup_data(t_data *data)
{
	if (!data)
		return ;
	if (data->mlx)
	{
		destroy_image(data->mlx, &data->texture.north);
		destroy_image(data->mlx, &data->texture.south);
		destroy_image(data->mlx, &data->texture.east);
		destroy_image(data->mlx, &data->texture.west);
		destroy_image(data->mlx, &data->texture.menu_start);
		destroy_image(data->mlx, &data->texture.menu_exit);
		destroy_image(data->mlx, &data->render_img);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_texture_paths(&data->texture);
	free_file_content(data->file_content);
}
