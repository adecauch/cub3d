/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:10:24 by ramahrez          #+#    #+#             */
/*   Updated: 2025/12/16 16:10:40 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_STRUCT_H
# define GET_NEXT_LINE_STRUCT_H

typedef struct s_vars
{
	int		str_buffer;
	int		str_size;
	int		line_lenght;
	int		read_size;
	char	*buffer;
}			t_vars;

#endif