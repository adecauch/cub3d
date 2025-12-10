/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:56:38 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/31 22:47:33 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strlcpy(char *src, char *dest, int l)
{
	int	i;

	i = 0;
	if (!src || !dest)
		return ;
	while (i + 1 < l && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < l)
	{
		dest[i] = 0;
	}
}

int	ft_test(t_vars *s_var)
{
	while (s_var->buffer[s_var->line_lenght]
		&&s_var->buffer[s_var->line_lenght] != '\n')
		s_var->line_lenght++;
	if (s_var->buffer[s_var->line_lenght] == '\n')
	{
		s_var->line_lenght++;
		return (0);
	}
	return (1);
}

int	ft_read_alloc_fd(t_vars *s_var, int fd)
{
	char	*temp;
	int		a;

	s_var->read_size = BUFFER_SIZE;
	while (ft_test(s_var) && s_var->read_size == BUFFER_SIZE)
	{
		if (s_var->str_size + s_var->read_size >= s_var->str_buffer)
		{
			temp = malloc(s_var->str_buffer * 2);
			if (!temp)
				return (-1);
			s_var->str_buffer *= 2;
			ft_strlcpy(s_var->buffer, temp, s_var->str_size + 1);
			free(s_var->buffer);
			s_var->buffer = temp;
		}
		a = s_var->str_size;
		s_var->read_size = read(fd, s_var->buffer + a, BUFFER_SIZE);
		if (s_var->read_size < 0)
			return (-1);
		s_var->str_size += s_var->read_size;
		s_var->buffer[s_var->str_size] = 0;
	}
	return (s_var->line_lenght);
}

void	*ft_nul(t_vars s_var, char *trace)
{
	ft_strlcpy("", trace, BUFFER_SIZE);
	return (free(s_var.buffer), NULL);
}

char	*get_next_line(int fd)
{
	t_vars		s_var;
	char		*ret;
	static char	trace[FD][BUFFER_SIZE] = {0};

	if ((fd < 0) || fd > FD || BUFFER_SIZE < 1)
		return (NULL);
	s_var.str_buffer = BUFFER_SIZE + 1;
	s_var.buffer = malloc(s_var.str_buffer);
	if (!s_var.buffer)
		return (NULL);
	s_var.str_size = 0;
	while (trace[fd][s_var.str_size])
		s_var.str_size++;
	ft_strlcpy(trace[fd], s_var.buffer, s_var.str_size + 1);
	s_var.line_lenght = 0;
	s_var.line_lenght = ft_read_alloc_fd(&s_var, fd);
	if (s_var.line_lenght == -1 || !s_var.buffer[0])
		return (ft_nul(s_var, trace[fd]));
	ret = malloc(s_var.line_lenght + 1);
	if (!ret)
		return (free(s_var.buffer), NULL);
	ft_strlcpy(s_var.buffer, ret, s_var.line_lenght + 1);
	ft_strlcpy(s_var.buffer + s_var.line_lenght, trace[fd],
		s_var.str_size - s_var.line_lenght + 1);
	return (free(s_var.buffer), ret);
}

//  int main(void)
//  {
//    int fd = open("exemple.txt", O_RDONLY);
//    char *str;
//    str = get_next_line(fd);
//    while(str)
//    {
//      printf("%s", str);
//      str = get_next_line(fd);
//    }
//    return (0);
//  }

// int main(void)
// {
// 	int fd = open("exemple2.txt", O_RDONLY);
// 	char *str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 		printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// }