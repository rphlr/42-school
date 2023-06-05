/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_destination.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:24 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:20:29 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_enemy_destination(t_enemy *enemy)
{
	void	(*move_functions[4])(t_enemy *);
	int		direction;

	move_functions[0] = enemy_left;
	move_functions[1] = enemy_right;
	move_functions[2] = enemy_up;
	move_functions[3] = enemy_down;
	if (enemy->x == enemy->destination_x && enemy->y == enemy->destination_y)
	{
		direction = get_random_direction();
		move_functions[direction](enemy);
	}
}

void	move_enemy_left(t_enemy *enemy)
{
	enemy->x -= enemy->move_speed;
	if (enemy->x < enemy->destination_x)
	{
		enemy->x = enemy->destination_x;
		enemy->state = 1;
	}
}

void	move_enemy_right(t_enemy *enemy)
{
	enemy->x += enemy->move_speed;
	if (enemy->x > enemy->destination_x)
	{
		enemy->x = enemy->destination_x;
		enemy->state = 1;
	}
}

void	move_enemy_up(t_enemy *enemy)
{
	enemy->y -= enemy->move_speed;
	if (enemy->y < enemy->destination_y)
	{
		enemy->y = enemy->destination_y;
		enemy->state = 1;
	}
}

void	move_enemy_down(t_enemy *enemy)
{
	enemy->y += enemy->move_speed;
	if (enemy->y > enemy->destination_y)
	{
		enemy->y = enemy->destination_y;
		enemy->state = 1;
	}
}
