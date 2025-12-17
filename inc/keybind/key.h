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

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17
# define KEY_PRESS_MASK 1L
# define STRUCTURE_NOTIFY_MASK 131072L

#endif
