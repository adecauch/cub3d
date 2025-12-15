/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_macos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:32:41 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/15 13:51:27 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_loop(t_data *data)
{
	if (data->state == MENU)
		render_menu(data);
	else if (data->state == GAME)
		render_game(data);
	return (0);
}

int	close_game(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	init_game(t_data *data)
{
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cube3D");
	data->render_img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->render_img.addr = mlx_get_data_addr(data->render_img.img,
			&data->render_img.bpp, &data->render_img.line_len,
			&data->render_img.endian);
	data->state = MENU;
	data->menu = MENU_START;
}

int	game(t_data *data)
{
	if (!data->mlx)
		return (1);
	init_game(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_game, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	return (0);
}
