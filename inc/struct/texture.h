/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:23:35 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/16 16:10:58 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "image.h"

typedef struct s_texture
{
	t_img	south;
	t_img	north;
	t_img	west;
	t_img	east;
	t_img	menu_exit;
	t_img	menu_start;
	int		floor_color;
	int		ceil_color;
}			t_texture;

#endif
