/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slender_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:00:25 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 16:00:38 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	update_slender_anim(t_data *data)
{
	data->slender.anim_tick++;
	data->slender.cur_frame = (data->slender.anim_tick / SLENDER_ANIM_SPEED)
		% data->slender.frame_count;
}

void	check_slender_catch(t_data *data)
{
	double	dx;
	double	dy;

	dx = data->player.x - data->slender.x;
	dy = data->player.y - data->slender.y;
	if (dx * dx + dy * dy < SLENDER_CATCH_DIST * SLENDER_CATCH_DIST)
		data->state = GAMEOVER;
}
