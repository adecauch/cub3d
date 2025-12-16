/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* parsing.h                                          :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: <votre_pseudo> <votre_mail@student.42.f>   +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/16 16:00:00 by <votre_pseudo>    #+#    #+#             */
/* Updated: 2025/12/16 16:00:00 by <votre_pseudo>   ###   ########.fr       */
/* */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stddef.h>
# include "struct/data.h"

/*Macro get next lline*/
#  define BUFFER_SIZE 1024
#  define FD 512
/* --- Couleurs d'erreur */
# define RED "\033[31m"
# define RESET "\033[0m"

/* ************************************************************************** */
/* FONCTIONS DE PARSING ET GESTION DES FICHIERS                               */
/* ************************************************************************** */

/* Initialisation et point d'entrée */
void	init_data(t_data *data);
int		ft_parsing(char *file_name, t_data *data);

/* Gestion des fichiers et lecture */
int		open_files(char *str);
int		ft_read_file(int fd, char ***file_content);
int		verif_files(char **files);

/* Extraction des données de configuration et de la carte */
int		extract_config(char **file_content, t_data *data);
int		extract_color(char *color, t_data *data);
int		extract_map(char **file_content, t_data *data);

/* Vérification et traitement de la carte */
int		ft_check_map(char **map);
void	extract_data_player(char **map, t_player *player);
int		skip_isspace(char *str);

/* ************************************************************************** */
/* FONCTIONS LIBFT / UTILS (Mémoire, Strings, Conversions)                    */
/* ************************************************************************** */

/* Gestion de la mémoire */
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, unsigned long n);
void	*ft_realloc(void *old, int old_size, int new_size, int data_size);

/* Manipulation de chaînes (Strings) */
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Conversions et vérifications */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/* Affichage et erreurs */
void	ft_putstr(char *str);
void	print_error(char *str);

/* ************************************************************************** */
/* DEBUG / AFFICHAGE (Non-normé)                                              */
/* ************************************************************************** */

void	ft_print_tab(char **tab);
void	ft_print_data(t_data data);

#endif