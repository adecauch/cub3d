/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:06 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/09 13:54:48 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum e_state
{
	START,
	GAME,
	MENU,
	GAMEOVER,
	WIN
} t_state;

typedef struct s_data
{
	t_enemy_node	*enemy_list;
	t_texture		texture;
	char			**map;
	t_player		player;
	t_state			state;
}					t_data;

int main(char **argv, int argc)
{
	printf("test\n");
}
