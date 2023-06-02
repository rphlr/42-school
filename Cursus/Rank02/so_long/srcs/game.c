/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:49 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:47:57 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_params *params)
{
	mlx_destroy_window(params->mlx, params->mlx_win);
	exit(0);
}

void	restart_game(t_params *params, t_map *map)
{
	char		*level_name;
	t_player	*player;
	t_enemy		*enemy;

	mlx_destroy_window(params->mlx, params->mlx_win);
	free(params->mlx);
	level_name = params->level_name;
	ft_printf(BLUE""NEXT_LEVEL_LOADING""RESET);
	map = create_valid_map(level_name);
	params->mlx = mlx_init();
	params->mlx_win = mlx_new_window(params->mlx, map->width * TILE,
			map->height * TILE, PROG_NAME);
	player = find_player_position(map);
	if (!player)
		error_and_exit(BOLD""RED""PLAYER_NOT_FOUND""RESET);
	enemy = find_enemy_position(map);
	if (!enemy)
		ft_printf(ITALIC""GREEN""NO_ENEMY""RESET);
	params->player = player;
	params->enemy = enemy;
	draw_map(map, params);
	game_loop(params, map);
}

void	game_loop(t_params *params, t_map *map)
{
	t_images			*images;
	t_animation_params	animation_params;

	images = params->images;
	animation_params.n_idle_frames = 6;
	animation_params.n_run_frames = 6;
	animation_params.frame_index_idle = 0;
	animation_params.frame_index_run = 0;
	animation_params.frame_index_enemy_idle = 0;
	animation_params.frame_index_enemy_run = 0;
	params->in_game = 1;
	while (params->in_game)
	{
		params->frame_counter = 0;
		process_events(params);
		process_player(params, map, &animation_params);
		if (params->enemy)
			process_enemy(params, map, &animation_params);
		display_game_info(params, map, animation_params.player_frame,
			animation_params.enemy_frame);
	}
}

void	process_events(t_params *params)
{
	mlx_hook(params->mlx_win, 2, 0, handle_key_press, params);
	mlx_hook(params->mlx_win, 3, 0, handle_key_release, params);
	mlx_hook(params->mlx_win, 17, 0, (void *)handle_window_close, params);
	update_player_state(params);
}

void	run_game(char *map_name)
{
	t_params	params;
	t_map		*map;
	t_images	images;

	check_map(map_name);
	ft_memset(params.keys, 0, sizeof(params.keys));
	params.mlx = mlx_init();
	map = create_valid_map(map_name);
	init_game_structures(&params, map, &images);
	draw_map(map, &params);
	game_loop(&params, map);
}
