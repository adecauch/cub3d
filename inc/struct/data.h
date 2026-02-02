/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:15:05 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 15:59:09 by adecauch         ###   ########.fr       */
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
