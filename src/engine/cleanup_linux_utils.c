/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_linux_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:03:45 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/21 17:19:08 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

static void	destroy_image(void *mlx, t_img *img)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(mlx, img->img);
}

void	cleanup_images(t_data *data)
{
	int	i;

	destroy_image(data->mlx, &data->texture.north);
	destroy_image(data->mlx, &data->texture.south);
	destroy_image(data->mlx, &data->texture.east);
	destroy_image(data->mlx, &data->texture.west);
	destroy_image(data->mlx, &data->texture.menu_start);
	destroy_image(data->mlx, &data->texture.menu_exit);
	destroy_image(data->mlx, &data->texture.door);
	i = -1;
	while (++i < 4)
	{
		destroy_image(data->mlx, &data->slender.frames[i]);
		destroy_image(data->mlx, &data->texture.win[i]);
		destroy_image(data->mlx, &data->texture.gameover[i]);
	}
	i = -1;
	while (++i < 4)
	{
		if (data->slender.frames[i].path)
			free(data->slender.frames[i].path);
	}
	destroy_image(data->mlx, &data->render_img);
}
