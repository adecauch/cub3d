#include "cub_3d.h"
#include "mlx.h"

// static int load_texture(t_img *texture, void *mlx)
// {
//     texture->img = mlx_xpm_file_to_image(mlx, texture->path, &texture->width, &texture->height);
//     if(!texture->img)
//     {
//         print_error("Error: load texture path:");
//         print_error(texture->path);
//         return (1);
//     }
//     texture->addr = mlx_get_data_addr(
//         texture->img, 
//         &texture->bpp,      // Bits per pixel (va être rempli)
//         &texture->line_len, // Longueur de ligne en octets (va être rempli)
//         &texture->endian    // Ordre des octets (va être rempli)
//     );
//     if (!texture->addr)
//     {
//         print_error("Error: Could not retrieve texture pixel address.\n");
//         return (1);
//     }
//     if (texture->width != 64 || texture->height != 64) 
//     {
//          print_error("Error: Texture size is not 64x64. Check your XPM files.\n");
//          return (1);
//     }
//     return (0);
// }

// static int  extract_texture(char *texture, t_data *data)
// {
//     if (!ft_strncmp(texture, "NO", 2))
//     {
//         data->texture.north.path = texture + 2 + skip_isspace(texture + 2);
//         load_texture(&data->texture.north, data->mlx);
//         return (1);
//     }
//     if (!ft_strncmp(texture, "SO", 2))
//     {
//         data->texture.south.path = texture + 2 + skip_isspace(texture + 2);
//         load_texture(&data->texture.south, data->mlx);
//         return (1);
//     }
//     if (!ft_strncmp(texture, "WE", 2))
//     {
//         data->texture.weast.path = texture + 2 + skip_isspace(texture + 2);
//         data->texture.weast.path[ft_strlen(data->texture.weast.path) - 1] = 0;
//         load_texture(&data->texture.weast, data->mlx);
//         return (1);
//     }
//     if (!ft_strncmp(texture, "EA", 2))
//     {
//         data->texture.east.path = texture + 2 + skip_isspace(texture + 2);
//         load_texture(&data->texture.east, data->mlx);
//         return (1);
//     }
//     return (0);
// }


// static int extract_element(char **file_content, t_data *data)
// {
//     int i;
//     int skip;
//     // int count;

//     i = 0;
//     // count = 0;
//     while (file_content[i])
//     {
//         skip = skip_isspace(file_content[i]);
//         if(ft_strchr("NSWEA", file_content[i][skip]))
//         {
//             if(extract_texture(file_content[i] + skip, data))
//                 return(1);
//         }
//         if(ft_strchr("CF", file_content[i][skip]))
//         {
//             if(extract_color(file_content[i] + skip, data))
//             return (0);
//         }
//         i++;
//     }
//     return(0);
// }

int extract_config(char **file_content, t_data *data)
{
    // if(extract_element(file_content, data))
        // return (1);
    if(extract_map(file_content,  data))
        return(1);
    extract_data_player(data->map, &data->player);
    return(0);
}