/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:32:41 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/09 20:58:15 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// La boucle principale
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
	// if (data->mlx)
		// mlx_destroy_display(data->mlx); pour LINUX
	// free(data->mlx);
	// je vais faire un fichier compatible avec les deux plus tard
	exit(0);
	return (0);
}

// Fonction principale du jeu
int	game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cub3D - Start Menu");
	data->state = MENU;
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_game, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	return (0);
}
