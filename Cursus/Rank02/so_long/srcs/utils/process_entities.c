/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:00:33 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 10:00:44 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_player(t_params *params, t_map *map,
	t_animation_params *animation_params)
{
	t_player	*player;

	process_player_state((t_process_player_state_params[]){{params, map,
		animation_params->n_idle_frames, animation_params->n_run_frames,
		&animation_params->frame_index_idle, &animation_params->frame_index_run,
		&animation_params->player_frame, params->images}});
	player = params->player;
	player->prev_x = player->x;
	player->prev_y = player->y;
	draw_map(map, params);
}

void	process_enemy(t_params *params, t_map *map,
	t_animation_params *animation_params)
{
	update_enemy_position(params, map, params->enemy);
	process_enemy_state((t_process_enemy_state_params[]){{params,
		animation_params->n_idle_frames, animation_params->n_run_frames,
		&animation_params->frame_index_enemy_idle,
		&animation_params->frame_index_enemy_run,
		&animation_params->enemy_frame, params->images}});
}
