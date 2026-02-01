/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:43:00 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/01 22:43:22 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "image.h"

# define SPRITE_COLLECTIBLE 0
# define SPRITE_EXIT        1
# define MAX_SPRITE_FRAMES  4
# define PICKUP_DISTANCE    0.5
# define ANIM_SPEED         15
# define SPRITE_TEX_SIZE    32

typedef struct s_sprite
{
	double	x;
	double	y;
	int		type;
	int		active;
	int		frame_count;
	t_img	frames[MAX_SPRITE_FRAMES];
	int		cur_frame;
}			t_sprite;

typedef struct s_sprite_proj
{
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		height;
	int		width;
	int		draw_start_x;
	int		draw_end_x;
	int		draw_start_y;
	int		draw_end_y;
}			t_sprite_proj;

typedef struct s_sprites
{
	t_sprite	*arr;
	int			count;
	int			total_collect;
	int			collected;
	int			anim_tick;
	double		*z_buffer;
	int			*order;
	double		*dist;
}				t_sprites;

#endif
