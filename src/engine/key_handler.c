/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:38:47 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/09 20:57:29 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// gestion des touches
int	key_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (data->state == MENU && keycode == KEY_ENTER)
	{
		printf("Lancement du jeu !\n");
		data->state = GAME;
		mlx_clear_window(data->mlx, data->win); // On efface le menu
	}
	return (0);
}
