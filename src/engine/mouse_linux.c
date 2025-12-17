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
	int				delta_x;
	double			rotation;
	static int		ignore_mouse = 0;

	(void)y;
	if (data->state != GAME)
		return (0);
	if (ignore_mouse)
	{
		ignore_mouse = 0;
		data->mouse_x = x;
		return (0);
	}
	delta_x = x - data->mouse_x;
	data->mouse_x = x;
	rotation = delta_x * 0.002;
	rotate_player(&data->player, rotation);
	if (x < 100 || x > W_WIDTH - 100)
	{
		data->mouse_x = W_WIDTH / 2;
		ignore_mouse = 1;
		mlx_mouse_move(data->mlx, data->win, W_WIDTH / 2, W_HEIGHT / 2);
	}
	return (0);
}
