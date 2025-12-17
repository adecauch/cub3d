/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/17 16:02:04 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include "data.h"

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
	return (game(&data));
}
