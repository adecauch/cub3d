/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:45:48 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/01 22:45:50 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_img	*get_sprite_frame(t_data *data, t_sprite *sprite)
{
	if (sprite->type == SPRITE_EXIT)
	{
		if (data->sprites.collected >= data->sprites.total_collect)
			return (&sprite->frames[1]);
		return (&sprite->frames[0]);
	}
	return (&sprite->frames[sprite->cur_frame]);
}

void	update_sprite_anim(t_data *data)
{
	int	i;

	data->sprites.anim_tick++;
	i = 0;
	while (i < data->sprites.count)
	{
		if (data->sprites.arr[i].active
			&& data->sprites.arr[i].frame_count > 0)
			data->sprites.arr[i].cur_frame = (data->sprites.anim_tick
					/ ANIM_SPEED) % data->sprites.arr[i].frame_count;
		i++;
	}
}
