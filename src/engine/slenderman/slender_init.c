/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slender_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:00:32 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 16:00:35 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

static int	generate_slender_placeholder(t_data *data)
{
	if (create_runtime_img(data, &data->slender.frames[0], SPRITE_TEX_SIZE))
		return (1);
	fill_img_diamond(&data->slender.frames[0], 0x1A1A1A);
	return (0);
}

static int	load_slender_frame(t_data *data)
{
	if (try_load_xpm(data, &data->slender.frames[0],
			"data/texture/slenderman.xpm"))
		return (generate_slender_placeholder(data));
	return (0);
}

int	init_slenderman(t_data *data)
{
	int	i;
	int	j;

	data->slender.active = 0;
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
				data->slender.active = 1;
				data->map[i][j] = '0';
			}
		}
	}
	if (!data->slender.active)
		return (0);
	data->slender.frame_count = 1;
	return (load_slender_frame(data));
}
