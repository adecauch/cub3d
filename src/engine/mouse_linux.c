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
	int				center_x;
	int				center_y;
	static int		first_move = 1;

	(void)y;
	if (data->state != GAME)
		return (0);
	center_x = W_WIDTH / 2;
	center_y = W_HEIGHT / 2;
	if (first_move)
	{
		first_move = 0;
		mlx_mouse_hide(data->mlx, data->win);
		mlx_mouse_move(data->mlx, data->win, center_x, center_y);
		return (0);
	}
	delta_x = x - center_x;
	if (delta_x != 0)
	{
		rotation = delta_x * 0.002;
		rotate_player(&data->player, rotation);
		mlx_mouse_move(data->mlx, data->win, center_x, center_y);
	}
	return (0);
}
