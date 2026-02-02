/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:32:41 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 16:02:17 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_loop(t_data *data)
{
	if (data->state == MENU)
		render_menu(data);
	else if (data->state == GAME)
	{
		update_player_movement(data);
		update_slenderman(data);
		update_sprite_anim(data);
		check_collectible_pickup(data);
		check_exit_condition(data);
		render_game(data);
	}
	else if (data->state == WIN)
		render_win(data);
	else if (data->state == GAMEOVER)
		render_gameover(data);
	return (0);
}

int	close_game(t_data *data)
{
	cleanup_data(data);
	exit(0);
	return (0);
}

void	init_game(t_data *data)
{
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	data->render_img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->render_img.addr = mlx_get_data_addr(data->render_img.img,
			&data->render_img.bpp, &data->render_img.line_len,
			&data->render_img.endian);
	data->state = MENU;
	data->menu = MENU_START;
	data->mouse_x = W_WIDTH / 2;
}

int	game(t_data *data)
{
	if (!data->mlx)
		return (1);
	init_game(data);
	mlx_hook(data->win, KEY_PRESS, KEY_PRESS_MASK, key_press, data);
	mlx_hook(data->win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, data);
	mlx_hook(data->win, MOTION_NOTIFY, POINTER_MOTION_MASK, mouse_move, data);
	mlx_hook(data->win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK, close_game,
		data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	return (0);
}
