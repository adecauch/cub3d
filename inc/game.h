/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:04:35 by ramahrez          #+#    #+#             */
/*   Updated: 2026/02/21 17:18:49 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define W_WIDTH 1280
# define W_HEIGHT 720

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "keybind/key.h"
# include "data.h"
# include "struct/ray.h"

/*-----key_handler.c-----*/

int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		mouse_move(int x, int y, t_data *data);

/*-----render.c-----*/

void	render_menu(t_data *data);
void	render_game(t_data *data);
void	render_win(t_data *data);
void	render_gameover(t_data *data);

/*-----raycasting/ray_init.c-----*/

void	init_ray(t_ray *ray, t_data *data, int x);
void	calculate_step_and_side_dist(t_ray *ray, t_data *data);
void	calculate_wall_x(t_ray *ray, t_data *data);

/*-----raycasting/ray_dda.c-----*/

void	perform_dda(t_ray *ray, t_data *data);
void	calculate_wall_distance(t_ray *ray, t_data *data);

/*-----raycasting/ray_render.c-----*/

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_texture_pixel(t_img *texture, int x, int y);
t_img	*get_wall_texture(t_ray *ray, t_data *data);
void	draw_wall_column(t_data *data, t_ray *ray, int x);

/*-----raycasting/raycasting.c-----*/

void	cast_ray(t_data *data, int x, t_ray *ray);
void	raycasting(t_data *data);

/*-----game.c-----*/

int		game_loop(t_data *data);
int		close_game(t_data *data);
void	init_game(t_data *data);
int		game(t_data *data);

/*-----player_movement.c-----*/

void	rotate_player(t_player *player, double rotation_speed);
void	move_player(t_data *data, double direction);
void	strafe_player(t_data *data, double direction);
void	update_player_movement(t_data *data);

/*-----minimap.c-----*/

void	render_minimap(t_data *data);
void	draw_minimap_content(t_data *data);

/*-----door.c-----*/

void	toggle_door(t_data *data);

/*-----sprite/sprite_init.c-----*/

int		init_sprites_from_map(t_data *data);

/*-----sprite/sprite_utils.c-----*/

void	sort_sprites(t_data *data);
void	project_sprite(t_data *data, t_sprite *sp, t_sprite_proj *p);

/*-----sprite/sprite_render.c-----*/

void	render_sprites(t_data *data);

/*-----sprite/sprite_anim.c-----*/

void	update_sprite_anim(t_data *data);
t_img	*get_sprite_frame(t_data *data, t_sprite *sprite);

/*-----sprite/placeholder_tex.c-----*/

int		generate_collect_frames(t_data *data, t_sprite *sprite);
int		generate_exit_frames(t_data *data, t_sprite *sprite);
int		try_load_xpm(t_data *data, t_img *img, char *path);
int		create_runtime_img(t_data *data, t_img *img, int size);
void	fill_img_diamond(t_img *img, int color);

/*-----slenderman/slender_init.c-----*/

int		init_slenderman(t_data *data);

/*-----slenderman/slender_move.c-----*/

void	update_slenderman(t_data *data);

/*-----slenderman/slender_anim.c-----*/

void	update_slender_anim(t_data *data);
void	check_slender_catch(t_data *data);

/*-----slenderman/slender_render.c-----*/

void	render_slenderman(t_data *data);

/*-----collectible.c-----*/

void	check_collectible_pickup(t_data *data);
void	check_exit_condition(t_data *data);

/*-----cleanup_macos.c / cleanup_linux.c-----*/

void	cleanup_data(t_data *data);
void	free_file_content(char **file_content);

/*-----cleanup_linux_utils.c-----*/

void	cleanup_images(t_data *data);

/*----------collectible.c--------------------*/

void	verif_collectible(t_data *data);

#endif
