/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:30:19 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/17 18:08:10 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	mouse_move(int x, int y, t_data *data)
{
	int		delta_x;
	double	rotation;

	(void)y;
	if (data->state != GAME)
		return (0);
	delta_x = x - data->mouse_x;
	data->mouse_x = x;
	rotation = delta_x * 0.002;
	rotate_player(&data->player, rotation);
	return (0);
}
