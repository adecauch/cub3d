/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:58:34 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/09 21:01:47 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# ifdef __APPLE__
#  include "key_mac.h"
# else
#  include "key_linux.h"
# endif

# define KeyPress 2
# define KeyRelease 3
# define DestroyNotify 17
# define KeyPressMask (1L<<0)
# define StructureNotifyMask (1L<<17)

#endif
