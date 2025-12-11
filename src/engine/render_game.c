/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:35:33 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/11 08:47:37 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_game(t_data *data)
{
	// raycasting(data);
	// en attendant
	mlx_string_put(data->mlx, data->win, 10, 20, 0x00FF00, "JEU EN COURS...");
}
