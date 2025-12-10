/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:57:16 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/09 22:25:46 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "cub_3d.h"
#include <unistd.h>

void ft_parsing(char *file_name, t_data *data)
{
    char **file_contnent;
    file_contnent = NULL;
    
    if(ft_read_file(open_files(file_name), &file_contnent))
        return ;
    if(verif_files(file_contnent))
        return ;
    if(extract_warpconfig(file_contnent, data))
        return ;
    // (void)data;
}