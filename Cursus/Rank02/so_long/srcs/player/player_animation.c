/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:25 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:01:53 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_idle_frames(t_params *params, t_images *images)
{
	char	*idle_frames[6];

	idle_frames[0] = "sprites/player/idle/frame1.xpm";
	idle_frames[1] = "sprites/player/idle/frame2.xpm";
	idle_frames[2] = "sprites/player/idle/frame3.xpm";
	idle_frames[3] = "sprites/player/idle/frame4.xpm";
	idle_frames[4] = "sprites/player/idle/frame5.xpm";
	idle_frames[5] = "sprites/player/idle/frame6.xpm";
	load_frames(params, idle_frames, sizeof(idle_frames) / sizeof(char *),
		(void **)images->player_idle);
}

void	load_player_run_frames(t_params *params, t_images *images)
{
	char	*run_frames[6];

	run_frames[0] = "sprites/player/run/frame1.xpm";
	run_frames[1] = "sprites/player/run/frame2.xpm";
	run_frames[2] = "sprites/player/run/frame3.xpm";
	run_frames[3] = "sprites/player/run/frame4.xpm";
	run_frames[4] = "sprites/player/run/frame5.xpm";
	run_frames[5] = "sprites/player/run/frame6.xpm";
	load_frames(params, run_frames, sizeof(run_frames) / sizeof(char *),
		(void **)images->player_run);
}

void	load_player_attack_frames(t_params *params, t_images *images)
{
	char	*attack_frames[8];

	attack_frames[0] = "sprites/player/attack/frame1.xpm";
	attack_frames[1] = "sprites/player/attack/frame2.xpm";
	attack_frames[2] = "sprites/player/attack/frame3.xpm";
	attack_frames[3] = "sprites/player/attack/frame4.xpm";
	attack_frames[4] = "sprites/player/attack/frame5.xpm";
	attack_frames[5] = "sprites/player/attack/frame6.xpm";
	attack_frames[6] = "sprites/player/attack/frame7.xpm";
	attack_frames[7] = "sprites/player/attack/frame8.xpm";
	load_frames(params, attack_frames, sizeof(attack_frames) / sizeof(char *),
		(void **)images->player_attack);
}

void	load_player_death_frames(t_params *params, t_images *images)
{
	char	*death_frames[9];

	death_frames[0] = "sprites/player/death/frame1.xpm";
	death_frames[1] = "sprites/player/death/frame2.xpm";
	death_frames[2] = "sprites/player/death/frame3.xpm";
	death_frames[3] = "sprites/player/death/frame4.xpm";
	death_frames[4] = "sprites/player/death/frame5.xpm";
	death_frames[5] = "sprites/player/death/frame6.xpm";
	death_frames[6] = "sprites/player/death/frame7.xpm";
	death_frames[7] = "sprites/player/death/frame8.xpm";
	death_frames[8] = "sprites/player/death/frame9.xpm";
	load_frames(params, death_frames, sizeof(death_frames) / sizeof(char *),
		(void **)images->player_death);
}

void	process_player_state(t_process_player_state_params *params)
{
	t_player	*player;
	t_images	*images;

	player = params->params->player;
	images = params->images;
	process_idle_state(params, player, images);
	process_run_state(params, player, images);
	process_attack_state(params, player, images);
	process_death_state(params, player, images);
	process_resurrection_state(params, player, images);
}
