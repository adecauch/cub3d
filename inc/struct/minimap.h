/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:15:10 by ramahrez          #+#    #+#             */
/*   Updated: 2026/01/08 13:45:19 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

typedef struct s_minimap
{
	int		size;
	int		width;
	int		height;
	int		map_width;
	int		map_height;
	int		radius;
	int		center_x;
	int		center_y;
	int		color_wall;
	int		color_floor;
	int		color_player;
	int		color_collectible;
	int		color_exit;
}	t_minimap;

#endif