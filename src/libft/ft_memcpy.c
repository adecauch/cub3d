/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:21:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/12/08 20:52:27 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	if (!dest && !src)
		return (NULL);
	src2 = (char *)src;
	dest2 = (char *)dest;
	while (n > 0)
	{
		*dest2 = *src2;
		src2++;
		dest2++;
		n--;
	}
	return (dest);
}
