/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:20 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/13 16:51:07 by adecauch         ###   ########.fr       */
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

/*-----render.c-----*/

void	render_menu(t_data *data);
void	render_game(t_data *data);

/*-----raycasting.c-----*/

void	raycasting(t_data *data);

/*-----game.c-----*/

int		game_loop(t_data *data);
int		close_game(t_data *data);
void	init_game(t_data * data);
int		game(t_data *data);

/*-----player_movement.c-----*/

void	rotate_player(t_player *player, double rotation_speed);
void	move_player(t_data *data, double direction);
void	strafe_player(t_data *data, double direction);

#endif
