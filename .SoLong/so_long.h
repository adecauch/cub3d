/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:46 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/23 12:46:05 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <mlx.h>
# include "./keybind/key.h"
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/*-----structures-----*/

typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*exit2;
	void	*collect;
	void	*cartman;
}			t_image;

typedef struct game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_image	image;
	int		x_map;
	int		y_map;
	int		player_x;
	int		player_y;
	int		moves;
	int		collects;
}			t_game;
void	free_image(t_game *game);
typedef struct s_draw
{
	void	*mlx;
	void	*win;
	char	c;
	int		x;
	int		y;
	t_image	image;
}	t_draw;

/*-----libft-----*/

char	*get_next_line(int fd);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t lendst);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_itoa(int n);
void	free_map(char **map);

/*-----game-----*/

void	init_game(t_game *g, char *map_file);
void	find_player(t_game *game);
void	change_exit_state(t_game *game);
void	handle_collect(t_game *game);
void	handle_exit(t_game *game, char c);
void	move_player(t_game *game, int dx, int dy);
int		handle_key(int keycode, t_game *game);
int		handle_cross(t_game *game);

/*-----parsing-----*/

char	**create_parse_map(char *file_name, int *x, int *y);

/*-----drawing-----*/

void	load_image(void *mlx, t_image *image);
void	draw_item(t_draw draw);
void	draw_line(t_draw *draw, char *line, int *x);
void	draw_map(void *mlx, void *win, char **map, t_image image);

#endif
