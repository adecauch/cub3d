/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:15:05 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/24 00:19:23 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "enum.h"
# include "image.h"
# include "player.h"
# include "texture.h"
# include "minimap.h"

typedef struct s_data
{
	t_minimap	minimap;
	t_texture	texture;
	t_img		render_img;
	char		**file_content;
	char		**map;
	t_player	player;
	int			keys[70000];
	int			mouse_x;
	t_state		state;
	t_menu		menu;
	void		*mlx;
	void		*win;
}	t_data;

#endif
