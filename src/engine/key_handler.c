/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:38:47 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/11 13:42:19 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	handle_game_keys(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		move_player(data, 1.0);
	if (keycode == KEY_S)
		move_player(data, -1.0);
	if (keycode == KEY_A)
		strafe_player(data, -1.0);
	if (keycode == KEY_D)
		strafe_player(data, 1.0);
	if (keycode == KEY_RIGHT)
		rotate_player(&data->player, 0.05);
	if (keycode == KEY_LEFT)
		rotate_player(&data->player, -0.05);
}

static void	handle_menu_keys(int keycode, t_data *data)
{
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_W || keycode == KEY_S)
	{
		if (data->menu == MENU_START)
			data->menu = MENU_EXIT;
		else
			data->menu = MENU_START;
	}
	if (keycode == KEY_ENTER)
	{
		if (data->menu == MENU_START)
		{
			data->state = GAME;
			mlx_clear_window(data->mlx, data->win);
		}
		else
			close_game(data);
	}
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (data->state == MENU)
		handle_menu_keys(keycode, data);
	else if (data->state == GAME)
		handle_game_keys(keycode, data);
	return (0);
}
