/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:01:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/21 17:01:02 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// char **ft_split(char *str, char c)
//{
//	char **tab;
//	int i = 0;
//	int j = 0;
//	int x = 0;

//	tab = malloc(10000);
//	while(i < 10000)
//	{
//		tab[i] = malloc(5000);
//		i++;
//	}
//	i = 0;
//	while(str[x])
//	{
//		tab[i][j] = str[x];
//		x++;
//		j++;
//		if(str[x] == c)
//		{
//			tab[i][j] = 0;
//			i++;
//			j = 0;
//			x++;
//		}
//	}
//	tab[i][j] = 0;

//	tab[++i] = NULL;
//	return(tab);
//}

// void	ft_print_tab(char **tab)
//{
//	int	i;

//	i = 0;
//	while (tab[i])
//	{
//		printf("%s\n", tab[i]);
//		i++;
//	}
//}

// int main(void)
//{
//	char *str = "salut";

//	int i = 0;
//	while(str[i])
//	{
//		write(1, &str[i], 1);

//	}
//	int i = 4;
//	printf("%d", (i == 5));
//}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str[], ft_strlen(str));
}

// char *str;
// char c;

//*str;