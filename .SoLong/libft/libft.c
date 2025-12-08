/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:44:24 by adecauch          #+#    #+#             */
/*   Updated: 2024/12/17 07:17:21 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t lendst)
{
	size_t	lensrc;
	size_t	i;

	lensrc = ft_strlen(src);
	i = 0;
	if (lendst > 0)
	{
		while ((i < lendst - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (lensrc);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (n < len)
		len = n;
	ft_strlcpy(dst, src, (len + 1));
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL && s2 == NULL)
		return (ft_strndup("", 1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (s1 == NULL)
		return (ft_strndup(s2, lens2));
	if (s2 == NULL)
		return (ft_strndup(s1, lens1));
	str = malloc(lens1 + lens2 + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, (lens1 + 1));
	ft_strlcpy(&str[lens1], s2, (lens2 + 1));
	free((char *)s1);
	return (str);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
