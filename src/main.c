/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/22 13:32:58 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include "data.h"
#include <stdlib.h>

//static void	set_test_map(t_data *data)
//{
//	char	**map;

//	map = malloc(sizeof(char *) * 13);
//	map[0] = ft_strdup("1111111111111");
//	map[1] = ft_strdup("1C0000C000001");
//	map[2] = ft_strdup("100000000s001");
//	map[3] = ft_strdup("1001110001001");
//	map[4] = ft_strdup("10C1010001001");
//	map[5] = ft_strdup("10010D0001001");
//	map[6] = ft_strdup("1001C100C1001");
//	map[7] = ft_strdup("1001110001001");
//	map[8] = ft_strdup("1000000000001");
//	map[9] = ft_strdup("100N0000C0X01");
//	map[10] = ft_strdup("1000000000001");
//	map[11] = ft_strdup("1111111111111");
//	map[12] = NULL;
//	data->map = map;
//	data->minimap.map_height = 12;
//	data->minimap.map_width = 13;
//}

	//set_test_map(data); utile a la fonction en bas si jamais je laisse
	//data->total_collectibles = 7;

//extract_data_player(data->map, &data->player);
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
