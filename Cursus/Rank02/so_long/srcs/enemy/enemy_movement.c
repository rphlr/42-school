/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:29 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 12:55:22 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_left(t_enemy *enemy)
{
	enemy->destination_x = enemy->x - TILE;
}

void	enemy_right(t_enemy *enemy)
{
	enemy->destination_x = enemy->x + TILE;
}

void	enemy_up(t_enemy *enemy)
{
	enemy->destination_y = enemy->y - TILE;
}

void	enemy_down(t_enemy *enemy)
{
	enemy->destination_y = enemy->y + TILE;
}

// Linear Feedback Shift Register
int	get_random_direction(void)
{
	static unsigned int	lfsr;
	unsigned int		bit;

	if (!lfsr)
		lfsr = 0xACE1u;
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	lfsr = (lfsr >> 1) | (bit << 15);
	return (lfsr % 4);
}
