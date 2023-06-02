/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:26:10 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:50:30 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mylib/includes/mylib.h"
# include "macros.h"
# include "struct.h"
# include <fcntl.h>

// game.c
void		close_window(t_params *params);
void		restart_game(t_params *params, t_map *map);
void		game_loop(t_params *params, t_map *map);
void		process_events(t_params *params);
void		run_game(char *map_name);

// player.c
t_player	*init_player(void);
void		set_player_position(t_player *player, int i, int j);
t_player	*find_player_position(t_map *map);
void		*player_resurrect(t_images *images, t_params *params,
				t_player *player, t_map *map);
void		*player_death(t_images *images, t_params *params, t_player *player,
				t_map *map);

// player_action.c
void		player_attack(t_images *images, t_params *params, t_player *player,
				t_map *map);
void		player_eating(t_params *params, t_map *map);
void		update_player_movement(t_params *params, t_player *player);
void		move_player(t_player *player, int move_x, int move_y);
void		update_player_position(t_params *params, t_map *map);

// player_animation.c
void		load_player_idle_frames(t_params *params, t_images *images);
void		load_player_run_frames(t_params *params, t_images *images);
void		load_player_attack_frames(t_params *params, t_images *images);
void		load_player_death_frames(t_params *params, t_images *images);
void		process_player_state(t_process_player_state_params *params);

// enemy.c
t_enemy		*init_enemy(void);
void		set_enemy_position(t_enemy *enemy, int i, int j);
t_enemy		*find_enemy_position(t_map *map);
void		process_enemy_state(t_process_enemy_state_params *params);
void		update_enemy_position(t_params *params, t_map *map, t_enemy *enemy);

// enemy_animation.c
void		load_enemy_idle_frames(t_params *params, t_images *images);
void		load_enemy_run_frames(t_params *params, t_images *images);
void		load_enemy_attack_frames(t_params *params, t_images *images);
void		load_enemy_death_frames(t_params *params, t_images *images);
void		move_enemy(t_enemy *enemy);

// map.c
t_map		*create_map(char *av);
int			is_closed_by_walls(t_map *map);
int			has_valid_elements(t_map *map, int start, int exit,
				int collectibles);
int			is_path_valid(t_map *map);
int			is_map_valid(t_map *map);

// map_processing.c
void		fill(char **tab, t_point size, t_point cur, char to_fill);
void		flood_fill(char **tab, t_point size, t_point begin);
int			map_exists(char *filename);
int			is_wall(t_map *map, int x, int y);
int			check_map_name(char *filename);

// map_checking.c
int			is_rectangle(t_map *map);
int			check_exit(t_params *params, t_map *map);
void		check_enemy(t_params *params);
void		check_map(char *map_name);
t_map		*create_valid_map(char *map_name);

// map_drawing.c
void		draw_map(t_map *map, t_params *params);
void		draw_floor(t_params *params, int i, int j);
void		draw_wall(t_params *params, int i, int j);
void		draw_sushi(t_params *params, int i, int j);
void		draw_dish(t_params *params, int i, int j);
void		draw_exit(t_params *params, int i, int j);

// utils.c
int			get_num_digits(int value);
char		*build_count_text(const char *text, int value);
int			extract_level(const char *filename);
void		calculate_edge_coordinates(t_point move, t_point collision,
				int *edge_x, int *edge_y);
t_point		calculate_speed(t_params *params);

// position_adjustment.c
void		adjust_x_position(t_player *player, int move_x, t_point collision,
				int new_x);
void		adjust_y_position(t_player *player, int move_y, t_point collision,
				int new_y);
t_point		calculate_new_pos(t_params *params);
void		handle_wall_detection(t_params *params, t_map *map,
				t_point new_pos);

// display.c
void		display_player_enemy_frames(t_params *params, void *player_frame,
				void *enemy_frame);
void		display_game_info(t_params *params, t_map *map,
				void *player_frame, void *enemy_frame);
void		display_move_count(t_params *params, t_player *player);
void		display_meal_count(t_params *params, t_player *player);

// images.c
t_images	*init_images(void);
void		load_images(t_params *params, t_images *images);
void		load_utils_images(t_params *params, t_images *images);
void		load_frames(t_params *params, char **frames, int num_frames,
				void **dest);

// background_image.c
t_images	*init_background_image(t_params *params);
void		swap_pixels(t_image_info *info, int x1, int y, int x2);
void		flip_horizontal_line(t_image_info *info, int width, int y);
void		flip_image_horizontally(t_image_info *info, int img_width,
				int img_height);
void		flip_all_images(t_params *params, t_images *images);

// enemy_movement.c
void		enemy_left(t_enemy *enemy);
void		enemy_right(t_enemy *enemy);
void		enemy_up(t_enemy *enemy);
void		enemy_down(t_enemy *enemy);
int			get_random_direction(void);

// enemy_destination.c
void		update_enemy_destination(t_enemy *enemy);
void		move_enemy_left(t_enemy *enemy);
void		move_enemy_right(t_enemy *enemy);
void		move_enemy_up(t_enemy *enemy);
void		move_enemy_down(t_enemy *enemy);

// error_handling.c
void		error_and_exit(const char *error_message);
void		check_enemy_wall_collision(t_map *map, t_enemy *enemy);

// initialization.c
void		init_game_structures(t_params *params, t_map *map,
				t_images *images);
int			main(int ac, char **av);
void		handle_window_close(t_params *params);

// key_handling.c
int			handle_key_press(int keycode, t_params *params);
int			handle_key_release(int keycode, t_params *params);

// map_creation.c
int			set_map_data(t_map *map, char *av);
int			set_map_size(t_map *map, char *av);

// element_position.c
t_point		find_element_position(t_map *map, char element);
int			count_sushis(t_map *map);

// player_speed.c
int			move_speed_x(t_params *params);
int			move_speed_y(t_params *params);

// player_state_processing.c
void		process_idle_state(t_process_player_state_params *params,
				t_player *player, t_images *images);
void		process_run_state(t_process_player_state_params *params,
				t_player *player, t_images *images);
void		process_attack_state(t_process_player_state_params *params,
				t_player *player, t_images *images);
void		process_death_state(t_process_player_state_params *params,
				t_player *player, t_images *images);

// player_resurrection.c
void		process_resurrection_state(t_process_player_state_params *params,
				t_player *player, t_images *images);

// process_entities.c
void		process_player(t_params *params, t_map *map,
				t_animation_params *animation_params);
void		process_enemy(t_params *params, t_map *map,
				t_animation_params *animation_params);

// map_loading.c
char		*load_next_map(t_map *map);

// player_state_update.c
void		update_player_state(t_params *params);

#endif
