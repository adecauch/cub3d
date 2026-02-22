/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:05:56 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/07 21:10:14 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "enum.h"
# include "image.h"
# include "player.h"
# include "texture.h"
# include "minimap.h"
# include "sprite.h"
# include "slenderman.h"

typedef struct s_data
{
	t_sprites		sprites;
	t_slenderman	slender;
	t_minimap		minimap;
	t_texture		texture;
	t_img			render_img;
	char			**file_content;
	char			**map;
	char			**map_backup;
	t_player		player;
	int				keys[70000];
	int				mouse_x;
	t_state			state;
	t_menu			menu;
	void			*mlx;
	void			*win;
	int				total_collectibles;
}	t_data;

#endif
