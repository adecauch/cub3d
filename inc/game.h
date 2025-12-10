/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:20 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/10 10:39:56 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#define W_WIDTH 1280
#define W_HEIGHT 720

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "keybind/key.h"
#include "data.h"

/*-----key_handler.c-----*/

int		key_handler(int keycode, t_data *data);

/*-----render_menu.c-----*/

void	render_menu(t_data *data);

/*-----render_game.c-----*/

void	render_game(t_data *data);

/*-----game.c-----*/

int		game(t_data *data);
int		game_loop(t_data *data);
int		close_game(t_data *data);

#endif
