/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:38:47 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/17 17:32:41 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (data->state == MENU)
		handle_menu_keys(keycode, data);
	else if (data->state == GAME && keycode >= 0 && keycode < 70000)
		data->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (data->state == GAME && keycode >= 0 && keycode < 70000)
		data->keys[keycode] = 0;
	return (0);
}
