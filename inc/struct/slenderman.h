/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slenderman.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:59:34 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 15:59:37 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLENDERMAN_H
# define SLENDERMAN_H

# include "image.h"

# define SLENDER_BASE_SPEED 0.015
# define SLENDER_MAX_SPEED 0.04
# define SLENDER_CATCH_DIST 0.5
# define SLENDER_FRAMES 4
# define SLENDER_ANIM_SPEED 10

typedef struct s_slenderman
{
	double	x;
	double	y;
	int		active;
	int		anim_tick;
	int		cur_frame;
	t_img	frames[SLENDER_FRAMES];
	int		frame_count;
}			t_slenderman;

#endif
