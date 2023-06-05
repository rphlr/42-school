/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_state_processing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:59:11 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:59:35 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_idle_state(t_process_player_state_params *params,
						t_player *player,
						t_images *images)
{
	if (player->state == 0 && player->is_death == 0)
	{
		*params->player_frame = images->player_idle[*params->frame_index_idle];
		*params->frame_index_idle = (*params->frame_index_idle + 1)
			% params->n_idle_frames;
	}
}

void	process_run_state(t_process_player_state_params *params,
						t_player *player,
						t_images *images)
{
	if (player->state == 1 && player->is_death == 0)
	{
		update_player_position(params->params, params->map);
		*params->player_frame = images->player_run[*params->frame_index_run];
		if (player->is_flipped_horizontal != images->is_flipped)
		{
			flip_all_images(params->params, images);
			images->is_flipped = player->is_flipped_horizontal;
		}
		*params->frame_index_run = (*params->frame_index_run + 1)
			% params->n_run_frames;
	}
}

void	process_attack_state(t_process_player_state_params *params,
							t_player *player,
							t_images *images)
{
	if (player->state == 2 && player->is_death == 0)
	{
		player_attack(images, params->params, player, params->map);
	}
}

void	process_death_state(t_process_player_state_params *params,
							t_player *player,
							t_images *images)
{
	if (player->state == 3 && player->is_death == 0)
	{
		*params->player_frame = player_death(images, params->params, player,
				params->map);
	}
	else if (player->is_death == 2)
	{
		*params->player_frame = player_death(images, params->params, player,
				params->map);
	}
}
