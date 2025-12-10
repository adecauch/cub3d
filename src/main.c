/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/10 10:41:12 by adecauch         ###   ########.fr       */
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
    ft_parsing(argv[1], &data);
    // ft_print_data(data);
	return (game(&data));
}
