/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:46:37 by ramahrez          #+#    #+#             */
/*   Updated: 2026/01/03 01:38:11 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "game.h"

char	**ft_tabdup(char **grid)
{
	int		rows;
	char	**new_grid;

	rows = 0;
	while (grid[rows])
		rows++;
	new_grid = malloc(sizeof(char *) * (rows + 1));
	if (!new_grid)
		return (NULL);
	rows = 0;
	while (grid[rows])
	{
		new_grid[rows] = ft_strdup(grid[rows]);
		if (!new_grid[rows])
		{
			free_file_content(new_grid);
			return (NULL);
		}
		rows++;
	}
	new_grid[rows] = 0;
	return (new_grid);
}
