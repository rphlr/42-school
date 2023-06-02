/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:26 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:04:01 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemy_idle_frames(t_params *params, t_images *images)
{
	char	*idle_frames[6];

	idle_frames[0] = "sprites/enemy/idle/frame1.xpm";
	idle_frames[1] = "sprites/enemy/idle/frame2.xpm";
	idle_frames[2] = "sprites/enemy/idle/frame3.xpm";
	idle_frames[3] = "sprites/enemy/idle/frame4.xpm";
	idle_frames[4] = "sprites/enemy/idle/frame5.xpm";
	idle_frames[5] = "sprites/enemy/idle/frame6.xpm";
	load_frames(params, idle_frames, sizeof(idle_frames) / sizeof(char *),
		(void **)images->enemy_idle);
}

void	load_enemy_run_frames(t_params *params, t_images *images)
{
	char	*run_frames[6];

	run_frames[0] = "sprites/enemy/run/frame1.xpm";
	run_frames[1] = "sprites/enemy/run/frame2.xpm";
	run_frames[2] = "sprites/enemy/run/frame3.xpm";
	run_frames[3] = "sprites/enemy/run/frame4.xpm";
	run_frames[4] = "sprites/enemy/run/frame5.xpm";
	run_frames[5] = "sprites/enemy/run/frame6.xpm";
	load_frames(params, run_frames, sizeof(run_frames) / sizeof(char *),
		(void **)images->enemy_run);
}

void	load_enemy_attack_frames(t_params *params, t_images *images)
{
	char	*attack_frames[11];

	attack_frames[0] = "sprites/enemy/attack/frame1.xpm";
	attack_frames[1] = "sprites/enemy/attack/frame2.xpm";
	attack_frames[2] = "sprites/enemy/attack/frame3.xpm";
	attack_frames[3] = "sprites/enemy/attack/frame4.xpm";
	attack_frames[4] = "sprites/enemy/attack/frame5.xpm";
	attack_frames[5] = "sprites/enemy/attack/frame6.xpm";
	attack_frames[6] = "sprites/enemy/attack/frame7.xpm";
	attack_frames[7] = "sprites/enemy/attack/frame8.xpm";
	attack_frames[8] = "sprites/enemy/attack/frame9.xpm";
	attack_frames[9] = "sprites/enemy/attack/frame10.xpm";
	attack_frames[10] = "sprites/enemy/attack/frame11.xpm";
	load_frames(params, attack_frames, sizeof(attack_frames) / sizeof(char *),
		(void **)images->enemy_attack);
}

void	load_enemy_death_frames(t_params *params, t_images *images)
{
	char	*death_frames[7];

	death_frames[0] = "sprites/enemy/death/frame1.xpm";
	death_frames[1] = "sprites/enemy/death/frame2.xpm";
	death_frames[2] = "sprites/enemy/death/frame3.xpm";
	death_frames[3] = "sprites/enemy/death/frame4.xpm";
	death_frames[4] = "sprites/enemy/death/frame5.xpm";
	death_frames[5] = "sprites/enemy/death/frame6.xpm";
	death_frames[6] = "sprites/enemy/death/frame7.xpm";
	load_frames(params, death_frames, sizeof(death_frames) / sizeof(char *),
		(void **)images->enemy_death);
}

void	move_enemy(t_enemy *enemy)
{
	enemy->state = 0;
	if (enemy->x < enemy->destination_x)
		move_enemy_right(enemy);
	else if (enemy->x > enemy->destination_x)
		move_enemy_left(enemy);
	if (enemy->y < enemy->destination_y)
		move_enemy_down(enemy);
	else if (enemy->y > enemy->destination_y)
		move_enemy_up(enemy);
}
