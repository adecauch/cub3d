#include <math.h>
#include "minimap.h"
#include "game.h"
#include "mlx.h"

void draw_minimap_circle(t_data *data)
{
    int x;
    int y;
    int dx;
    int dy;
    
    y = data->minimap.center_y - data->minimap.radius;
    while (y <= data->minimap.center_y + data->minimap.radius)
    {
        x = data->minimap.center_x - data->minimap.radius;
        while (x <= data->minimap.center_x + data->minimap.radius)
        {
            dx = x - data->minimap.center_x;
            dy = y - data->minimap.center_y;
            if ((dx * dx) + (dy * dy) <= (data->minimap.radius * data->minimap.radius))
            {
                if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
                    my_mlx_pixel_put(&data->render_img, x, y, data->minimap.color_wall); 
            }
            x++;
        }
        y++;
    }
}

void draw_player_dot(t_data *data)
{
    const int center_x = data->minimap.center_x;
    const int center_y = data->minimap.center_y;
    const int player_color = data->minimap.color_player;
    
    const int dot_size = 4; 
    
    int i = -(dot_size / 2);
    while (i < (dot_size / 2)) 
    {
        int j = -(dot_size / 2);
        while (j < (dot_size / 2))
        {
            my_mlx_pixel_put(&data->render_img, center_x + j, center_y + i, player_color);
            j++;
        }
        i++;
    }
}

void render_minimap(t_data *data)
{
	draw_minimap_circle(data);
	draw_minimap_content(data);
	draw_player_dot(data);
}
