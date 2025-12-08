#ifndef DATA_H
#define DATA_H

#include "enemy_struct.h"
#include "texture_struct.h"

typedef struct s_data
{
    t_enemy_node *enemy_list;
    t_texture texture;
    char **map;
    t_player player;
    
} t_data;

#endif