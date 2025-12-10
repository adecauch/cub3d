#ifndef CUB_3D_H
#define CUB_3D_H

#include <stddef.h>
#include "struct/data.h"

void init_data(t_data *data);

////////////////////////////// todo parsing

int ft_parsing(char *file_name, t_data *data);
int ft_read_file(int fd, char ***file_content);
int open_files(char *str);
int verif_files(char **files);
int skip_isspace(char *str);
int	ft_check_map(char **map);
void extract_color(char *color, t_data *data);
int extract_config(char **file_content, t_data *data);
int extract_map(char **file_content, t_data *data);

//////////////////////////// libft

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, unsigned long n);
void	ft_putstr(char *str);
void print_error(char *str);
void	*ft_realloc(void *old, int old_size, int new_size, int data_size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int	ft_strncmp(const char	*s1, const char	*s2, unsigned int n);
char	*ft_strchr(const char *str, int c);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

//////////////////////////////////  ! DEBUG

void ft_print_tab(char **tab);
void ft_print_data(t_data data);

#endif
