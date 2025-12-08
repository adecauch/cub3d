/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:32 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/06 09:11:09 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.cartman);
	mlx_destroy_image(game->mlx, game->image.collect);
	mlx_destroy_image(game->mlx, game->image.exit2);
	mlx_destroy_image(game->mlx, game->image.exit);
	mlx_destroy_image(game->mlx, game->image.floor);
	mlx_destroy_image(game->mlx, game->image.wall);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	init_game(&game, argv[1]);
	find_player(&game);
	draw_map(game.mlx, game.win, game.map, game.image);
	ft_putstr("Moves: 0\n");
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
