/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:31:52 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/13 17:22:01 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_img
{
	int		width;
	int		height;
	char	*path;
	char	*addr;
	void	*img;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

#endif
