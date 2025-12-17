/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_macos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:31:15 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/17 17:52:06 by adecauch         ###   ########.fr       */
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
	if (x < 100 || x > W_WIDTH - 100)
	{
		data->mouse_x = W_WIDTH / 2;
		mlx_mouse_move(data->win, W_WIDTH / 2, W_HEIGHT / 2);
	}
	return (0);
}
