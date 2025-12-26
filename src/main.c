/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/26 15:34:45 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include "data.h"
#include <stdlib.h>

static char	**create_test_map_with_door(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 8);
	map[0] = ft_strdup("1111111");
	map[1] = ft_strdup("1000001");
	map[2] = ft_strdup("1000001");
	map[3] = ft_strdup("111D11111");
	map[4] = ft_strdup("100000D01");
	map[5] = ft_strdup("100N00111");
	map[6] = ft_strdup("1111111");
	map[7] = NULL;
	return (map);
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
	data.map = create_test_map_with_door();
	extract_data_player(data.map, &data.player);
	return (game(&data));
}
