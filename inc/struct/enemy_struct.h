/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:27:00 by adecauch          #+#    #+#             */
/*   Updated: 2025/12/11 13:53:11 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_STRUCT_H
# define ENEMY_STRUCT_H

typedef struct s_player
{
    double x;
    double y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;

    double speed;
    double health;
    int damage;
    //peut etre on rajoute une structure arme si on en meets plusieurs
} t_player;

typedef struct s_enemy
{
    double      x;
    double      y;
    double      dir_x; //vers ou il regarde
    double      dir_y;

    double      speed;
    int         health;
    int         damage;
    int         is_alive;   // 1 = vivant, 0 = mort

    double      dist_to_player; // distance calculée pour le raycasting / IA
}   t_enemy;


typedef struct s_enemy_node
{
    t_enemy enemy;
    struct s_enemy_node *next;
    
} t_enemy_node; // utile pour faire un sponeur d'enemy (on en cree a tout moment c'est simple d'en cree)

#endif
