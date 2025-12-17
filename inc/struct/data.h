/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:15:05 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/16 16:10:11 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "enum.h"
# include "image.h"
# include "player.h"
# include "texture.h"

typedef struct s_data
{
	t_texture	texture;
	t_img		render_img;
	char		**file_content;
	char		**map;
	t_player	player;
	t_state		state;
	t_menu		menu;
	void		*mlx;
	void		*win;
}				t_data;

#endif
