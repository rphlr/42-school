/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:37 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:21:21 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(const char *error_message)
{
	perror(error_message);
	exit(1);
}

void	check_enemy_wall_collision(t_map *map, t_enemy *enemy)
{
	int	center_x;
	int	center_y;

	center_x = TILE / 2;
	center_y = TILE / 2;
	if (is_wall(map, (enemy->destination_x + center_x) / TILE,
			(enemy->destination_y + center_y) / TILE))
	{
		enemy->destination_x = enemy->x;
		enemy->destination_y = enemy->y;
	}
}
