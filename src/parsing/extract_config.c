#include "cub_3d.h"


static int extract_texture(char *texture, t_data *data)
{
    if (!ft_strncmp(texture, "NO", 2))
        data->texture.north.path = texture + 2 + skip_isspace(texture + 2);
    if (!ft_strncmp(texture, "SO", 2))
        data->texture.south.path = texture + 2 + skip_isspace(texture + 2);
    if (!ft_strncmp(texture, "WE", 2))
        data->texture.weast.path = texture + 2 + skip_isspace(texture + 2);
    if (!ft_strncmp(texture, "EA", 2))
        data->texture.weast.path = texture + 2 + skip_isspace(texture + 2);
}

static int extract_element(char **file_content, t_data *data)
{
    int i;
    int skip;
    int count;

    i = 0;
    count = 0;
    while (file_content[i])
    {
        skip = skip_isspace(file_content[i]);
        if(ft_strchr("NSWEA", file_content[i][skip]))
            extract_texture(file_content, data);
    }
}

int extract_config(char **file_content, t_data *data)
{

}