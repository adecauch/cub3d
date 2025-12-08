/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:22:48 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/09 00:06:09 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"
#include"data.h"

int main(int ac, char **av)
{
    t_data data;
    if(ac != 2)
        return(print_error("Error: argument"), 1);
    ft_parsing(av[1], data);
    
}