/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/22 18:43:05 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include "data.h"
#include <stdlib.h>

static int	init_game_data(t_data *data)
{
	if (init_sprites_from_map(data))
		return (print_error("Error: sprite init failed"), 1);
	if (init_slenderman(data))
		return (print_error("Error: slenderman init failed"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error("Error: argument"), 1);
	init_data(&data);
	if (!data.mlx)
	{
		close_game(&data);
		return (print_error("Error: MLX initialization failed."), 1);
	}
	if (ft_parsing(argv[1], &data))
	{
		close_game(&data);
		return (1);
	}
	if (init_game_data(&data))
	{
		close_game(&data);
		return (1);
	}
	return (game(&data));
}
