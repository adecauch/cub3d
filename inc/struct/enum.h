/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:19:17 by adecauch          #+#    #+#             */
/*   Updated: 2026/02/01 22:42:32 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_state
{
	GAME,
	MENU,
	WIN
}	t_state;

typedef enum e_menu
{
	MENU_START,
	MENU_EXIT
}	t_menu;

#endif
