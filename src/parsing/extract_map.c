/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:43:01 by hectordavro       #+#    #+#             */
/*   Updated: 2025/12/09 22:25:08 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

// static void

int extract_map(char **file_content, t_data *data)
{
    int i = 0;
    
    while(file_content[i])
    {
        if(file_content[i][skip_isspace(file_content[i])] == '1')
        {
            data->map = file_content + i;
            break;
        }
        i++;
    }
    
    return(0);
}
