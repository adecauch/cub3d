/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:20 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/10 08:07:50 by adecauch         ###   ########.fr       */
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

typedef enum e_state
{
	START,
	GAME,
	MENU,
	GAMEOVER,
	WIN
} t_state;

typedef struct s_player
{
    double x;
    double y;
    double dir_x;
    double dir_y;

    double speed;
    double health;
    int damage;
} t_player;

typedef struct s_enemy
{
    double      x;
    double      y;
    double      dir_x; //vers ou il regarde
    double      dir_y;

    double      speed;
    int         health;
    int         damage;
    int         is_alive;   // 1 = vivant, 0 = mort

    double      dist_to_player; // distance calculée pour le raycasting / IA
}   t_enemy;


typedef struct s_enemy_node
{
    t_enemy enemy;
    struct s_enemy_node *next;
} t_enemy_node;

typedef struct s_img
{
    int     width;
    int     height;
    char    *path;
    char    *addr;
    void    *img;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_texture
{
    t_img south;
    t_img north;
    t_img weast;
    t_img east;
    int floor_color;
    int ceil_color;
}   t_texture ;

typedef struct s_data
{
	t_enemy_node	*enemy_list;
	t_texture		texture;
	char			**map;
	t_player		player;
	t_state			state;
	void			*mlx;
	void			*win;
}					t_data;

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
