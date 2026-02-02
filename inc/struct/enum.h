/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:19:17 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/02 15:59:16 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_state
{
	GAME,
	MENU,
	WIN,
	GAMEOVER
}	t_state;

typedef enum e_menu
{
	MENU_START,
	MENU_EXIT
}	t_menu;

#endif
