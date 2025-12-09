/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:35:56 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/09 20:58:15 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_menu(t_data *data) {
	// en attendant
	mlx_string_put(data->mlx, data->win, W_WIDTH / 2 - 50, W_HEIGHT / 2, 
		0xFFFFFF, "CUB3D - PRESS ENTER");
}
