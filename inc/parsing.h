/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <rayenmahrez@student.42.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:09:35 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/09 02:44:42 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define BUFFER_SIZE 1024
# define FD 512
# define RED "\033[31m"
# define RESET "\033[0m"

# include "struct/data.h"
# include <stddef.h>

/*-----init_data.c-----*/

void	init_data(t_data *data);

/*-----parsing.c-----*/

int		ft_parsing(char *file_name, t_data *data);

/*-----read_file.c-----*/

int		open_files(char *str);
int		ft_read_file(int fd, char ***file_content);

/*-----verif_file.c-----*/

int		verif_textures(char **files);

/*-----extract_config.c-----*/

int		extract_config(char **file_content, t_data *data);

/*-----extract_color.c-----*/

int		extract_color(char *color, t_data *data);

/*-----extract_map_data.c-----*/

int		extract_map_data(char **file_content, t_data *data);

/*-----verif_map.c-----*/

int		ft_check_path_and_collectibles(char **map, t_data *data);
int		extract_data_player(char **map, t_player *player);
int		verif_door(char **map);

/*-----string_utils.c-----*/

int		skip_isspace(char *str);

/*-----libft-----*/

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, unsigned long n);
void	*ft_realloc(void *old, int old_size, int new_size, int data_size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr(char *str);
void	print_error(char *str);
char	*get_next_line(int fd);
char	**ft_tabdup(char **grid);
char	*ft_itoa(int nb);
/*-----debug-----*/

void	ft_print_tab(char **tab);
void	ft_print_data(t_data data);

/*-----------extract_config_utils.c---------*/

int		load_texture(t_img *texture, void *mlx);
int		extract_texture(char *texture, t_data *data);
int		load_menu(t_data *data);

#endif
