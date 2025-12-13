/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:53:38 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/08 15:01:33 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "color.h"

void print_error(char *str)
{
    ft_putstr(RED);
    ft_putstr(str);
    ft_putstr(RESET);
}
