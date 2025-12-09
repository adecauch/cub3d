#ifndef TEXTURE_STRUC_H
#define TEXTURE_STRUC_H

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

#endif