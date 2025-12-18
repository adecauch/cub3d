/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:35:33 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/17 23:11:53 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ray.h>

void	cast_ray(t_data *data, int x, t_ray *ray)
{
	init_ray(ray, data, x);
	calculate_step_and_side_dist(ray, data);
	perform_dda(ray, data);
	calculate_wall_distance(ray, data);
	calculate_wall_x(ray, data);
}

void	raycasting(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < W_WIDTH)
	{
		cast_ray(data, x, &ray);
		ray.line_height = (int)(W_HEIGHT / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + W_HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_height / 2 + W_HEIGHT / 2;
		if (ray.draw_end >= W_HEIGHT)
			ray.draw_end = W_HEIGHT - 1;
		draw_wall_column(data, &ray, x);
		x++;
	}
	render_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->render_img.img, 0, 0);
}
