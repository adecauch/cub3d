/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:35:56 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/11 08:47:37 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_menu(t_data *data)
{
	if (data->menu == MENU_START)
		mlx_put_image_to_window(data->mlx, data->win, data->texture.menu_start.img, 0, 0);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->texture.menu_exit.img, 0, 0);
}
