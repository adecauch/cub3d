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

typedef struct s_data
{
    t_enemy_node *enemy_list;
    t_texture texture;
    char **map;
    t_player player;
    t_state state;
    void *mlx;
    void *win;
} t_data;

#endif