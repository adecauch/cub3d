/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/09 20:40:48 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Cub3D - Start Menu");
	data.state = MENU; // On commence sur le menu
	// clavier
	mlx_hook(data.win, KeyPress, KeyPressMask, key_handler, &data);
	// croix rouge
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, close_game, &data);
	// boucle de rendu
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
