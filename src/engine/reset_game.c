/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:54:52 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/22 19:09:47 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

static void	reset_slender_pos(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 's')
			{
				data->slender.x = j + 0.5;
				data->slender.y = i + 0.5;
				data->map[i][j] = '0';
				return ;
			}
		}
	}
}

static void	reset_collectibles(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sprites.count)
	{
		if (data->sprites.arr[i].type == SPRITE_COLLECTIBLE)
			data->sprites.arr[i].active = 1;
		i++;
	}
	data->sprites.collected = 0;
	data->player.collected = 0;
}

void	reset_game(t_data *data)
{
	free_file_content(data->map);
	data->map = ft_tabdup(data->map_backup);
	extract_data_player(data->map, &data->player);
	reset_slender_pos(data);
	reset_collectibles(data);
	ft_bzero(data->keys, sizeof(data->keys));
	data->state = GAME;
}
