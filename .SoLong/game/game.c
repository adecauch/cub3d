/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:11:09 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/06 09:11:09 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_game *g, char *map_file)
{
	g->map = create_parse_map(map_file, &g->x_map, &g->y_map);
	g->mlx = mlx_init();
	load_image(g->mlx, &g->image);
	g->win = mlx_new_window(g->mlx, g->x_map * 64, g->y_map * 64, "So Long");
	g->moves = 0;
	g->collects = 0;
	g->player_x = 0;
	g->player_y = 0;
	mlx_hook(g->win, 17, 0, handle_cross, g);
}

void	change_exit_state(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'E')
				game->map[i][j] = 'e';
			j++;
		}
		i++;
	}
}

void	handle_collect(t_game *game)
{
	game->collects--;
	if (game->collects == 0)
		change_exit_state(game);
}

void	handle_exit(t_game *game, char c)
{
	if (game->collects == 0 && c == '0')
	{
		free_map(game->map);
		free_image(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	else if (c == '1' )
	{
		free_map(game->map);
		free_image(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	x;
	int	y;

	x = game->player_x + dx;
	y = game->player_y + dy;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		handle_collect(game);
	if (game->map[y][x] == 'E' || game->map[y][x] == 'e')
	{
		handle_exit(game, '0');
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->moves++;
	ft_putstr("Moves: ");
	ft_putstr(ft_itoa(game->moves));
	ft_putstr("\n");
	draw_map(game->mlx, game->win, game->map, game->image);
}
