/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:23:35 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 15:59:51 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "image.h"

# define WIN_FRAMES 4
# define WIN_ANIM_SPEED 30
# define GAMEOVER_FRAMES 4
# define GAMEOVER_ANIM_SPEED 30

typedef struct s_texture
{
	t_img	south;
	t_img	north;
	t_img	west;
	t_img	east;
	t_img	menu_exit;
	t_img	menu_start;
	t_img	door;
	t_img	win[WIN_FRAMES];
	int		win_tick;
	t_img	gameover[GAMEOVER_FRAMES];
	int		gameover_tick;
	int		floor_color;
	int		ceil_color;
}			t_texture;

#endif
