#ifndef DATA_H
#define DATA_H

#include "enemy_struct.h"
#include "texture_struct.h"

typedef enum e_state
{
    START,
    GAME,
    MENU,
    GAMEOVER,
    WIN
} t_state;

typedef enum e_menu
{
    MENU_START,
    MENU_EXIT
} t_menu;

typedef struct s_data
{
    t_enemy_node *enemy_list;
    t_texture texture;
    char **map;
    t_player player;
    t_state state;
    t_menu menu;
    void *mlx;
    void *win;
} t_data;

#endif