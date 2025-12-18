#ifndef MINIMAP_STRUCT_H
#define MINIMAP_STRUCT_H

typedef struct s_minimap
{
    int         size;   
    int         width;   
    int         height; 
    int         map_width; 
    int         map_height;
    int         radius;   
    int         center_x;  
    int         center_y;   
    int         color_wall; 
    int         color_floor; 
    int         color_player;
    int         margin;     
    double      scale_factor; 
}   t_minimap;

#endif