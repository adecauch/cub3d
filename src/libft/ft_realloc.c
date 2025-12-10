/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:55:08 by ramahrez          #+#    #+#             */
/*   Updated: 2025/12/08 20:52:42 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"
#include <stdlib.h>

void	*ft_realloc(void *old, int old_size, int new_size, int data_size)
{
	void	*ptr;

	ptr = malloc(new_size * data_size);
	if (!ptr)
		return (NULL);
	if (old)
	{
		if (old_size < new_size)
			ft_memcpy(ptr, old, (old_size) * data_size);
		else
			ft_memcpy(ptr, old, (new_size) * data_size);
	}
	if (new_size > old_size)
		ft_bzero((char *)ptr + old_size * data_size, (new_size
				- old_size) * data_size);
	free(old);
	return (ptr);
}
