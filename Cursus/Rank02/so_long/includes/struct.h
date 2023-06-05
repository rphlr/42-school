/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:01:38 by marvin            #+#    #+#             */
/*   Updated: 2023/04/09 09:01:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// # include "so_long.h"

// Number of keys
# define NUM_KEYS 127

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_collision
{
	int	x;
	int	y;
	int	center_x;
	int	center_y;
}	t_collision;

typedef struct s_map
{
	int		width;
	int		height;
	char	*filename;
	char	**data;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	state;
	int	is_death;
	int	last_moving_direction;
	int	is_flipped_horizontal;
	int	destination_x;
	int	destination_y;
	int	prev_x;
	int	prev_y;
	int	left_moves;
	int	right_moves;
	int	up_moves;
	int	down_moves;
	int	sushis_eaten;
	int	num_resurrections;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	destination_x;
	int	destination_y;
	int	move_speed;
	int	state;
}	t_enemy;

typedef struct s_image_info
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
}	t_image_info;

typedef struct s_images
{
	void	*player_idle[6];
	void	*player_run[6];
	void	*player_attack[8];
	void	*player_death[9];
	void	*enemy_idle[6];
	void	*enemy_run[6];
	void	*enemy_attack[11];
	void	*enemy_death[7];
	void	*wall;
	void	*floor;
	void	*exit;
	void	*taco;
	void	*sushi;
	void	*dish;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		is_flipped;
	int		current_level;
}	t_images;

typedef struct s_game_state {
	t_player	*player;
	t_enemy		*enemy;
	t_map		*map;
	t_images	*images;
	int			n_idle_frames;
	int			n_run_frames;
	int			*frame_index_idle;
	int			*frame_index_run;
	int			*frame_index_enemy_idle;
	int			*frame_index_enemy_run;
	void		**player_frame;
	void		**enemy_frame;
}	t_game_state;

typedef struct s_params
{
	void		*mlx;
	void		*mlx_win;
	t_images	*bg_img;
	t_map		*map;
	int			keys[NUM_KEYS];
	t_player	*player;
	t_enemy		*enemy;
	int			running;
	int			frame_counter;
	int			warrior_state;
	int			warrior_x;
	int			warrior_y;
	t_images	*images;
	void		*buffer;
	int			in_game;
	char		*level_name;
}	t_params;

typedef struct s_process_player_state_params
{
	t_params	*params;
	t_map		*map;
	int			n_idle_frames;
	int			n_run_frames;
	int			*frame_index_idle;
	int			*frame_index_run;
	void		**player_frame;
	t_images	*images;
}	t_process_player_state_params;

typedef struct s_process_enemy_state_params
{
	t_params	*params;
	int			n_idle_frames;
	int			n_run_frames;
	int			*frame_index_enemy_idle;
	int			*frame_index_enemy_run;
	void		**enemy_frame;
	t_images	*images;
}	t_process_enemy_state_params;

typedef struct s_animation_params
{
	int		n_idle_frames;
	int		n_run_frames;
	int		frame_index_idle;
	int		frame_index_run;
	void	*player_frame;
	int		n_enemy_frames;
	int		frame_index_enemy_idle;
	int		frame_index_enemy_run;
	void	*enemy_frame;
}	t_animation_params;

#endif