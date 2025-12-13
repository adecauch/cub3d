/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:19:40 by lobriott          #+#    #+#             */
/*   Updated: 2025/12/08 21:24:44 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parsing.h"

void	ft_putstr(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(1, str, i);
}
