/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/10 11:45:45 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "cub_3d.h"
#include "data.h"

int	main(int argc, char **argv)
{
	t_data	data;

    init_data(&data);
    if(argc != 2)
        return(print_error("Error: argument"), 1);
    if(ft_parsing(argv[1], &data))
        return(1);
    // ft_print_data(data);
	return (game(&data));
}
