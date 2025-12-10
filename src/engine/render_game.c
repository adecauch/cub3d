/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:35:33 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/10 15:45:14 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_game(t_data *data)
{
	// raycasting(data);
	// en attendant
	mlx_string_put(data->mlx, data->win, 10, 20, 0x00FF00, "JEU EN COURS...");
	// mlx_put_image_to_window(
    // data->mlx,
    // data->win,
    // data->texture.east.img,
    // 0,
    // 0
// );
}
