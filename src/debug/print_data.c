#include "cub_3d.h"
#include <stdio.h>

void ft_print_data(t_data data)
{
    printf("---------------------map--------------------\n");
    printf("map = \n");
    ft_print_tab(data.map);
    printf("---------------------player--------------------\n");
    printf("player position x = [%f]\n", data.player.x);
    printf("player position y = [%f]\n", data.player.y);
    printf("player direction x = [%f]\n", data.player.dir_x);
    printf("player direction y = [%f]\n", data.player.dir_y);
    printf("player speed  = [%f]\n", data.player.speed);
    printf("player health  [%f]\n", data.player.health);
    printf("player damage  [%d]\n", data.player.damage);
    printf("---------------------texture--------------------\n");
    printf("north texture path = [%s]\n", data.texture.north.path);
    printf("weast texture path = [%s]\n", data.texture.weast.path);
    printf("east texture path = [%s]\n", data.texture.east.path);
    printf("south texture path = [%s]\n", data.texture.south.path);
    printf("floor color = [%d]\n", data.texture.floor_color);
    printf("ceil color = [%d]\n", data.texture.ceil_color);
}