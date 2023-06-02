/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_adjustment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:30 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:13:19 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	adjust_x_position(t_player *player, int move_x, t_point collision,
			int new_x)
{
	int	x_diff;

	x_diff = collision.x - new_x;
	if (x_diff >= 0 && x_diff < COLLISION_THRESHOLD && move_x != 0)
	{
		if (move_x < 0)
			player->x = collision.x - (TILE / 2 + COLLISION_MARGIN);
		else
			player->x = collision.x - (TILE / 2 - COLLISION_MARGIN);
	}
	else if (x_diff < 0 && - x_diff < COLLISION_THRESHOLD && move_x != 0)
	{
		if (move_x < 0)
			player->x = collision.x - (TILE / 2 + COLLISION_MARGIN);
		else
			player->x = collision.x - (TILE / 2 - COLLISION_MARGIN);
	}
	else if (move_x != 0)
	{
		if (move_x > 0)
			player->x += COLLISION_THRESHOLD;
		else
			player->x -= COLLISION_THRESHOLD;
	}
}

void	adjust_y_position(t_player *player, int move_y, t_point collision,
		int new_y)
{
	int	y_diff;

	y_diff = collision.y - new_y;
	if (y_diff >= 0 && y_diff < COLLISION_THRESHOLD && move_y != 0)
	{
		if (move_y < 0)
			player->y = collision.y - (TILE / 2 + COLLISION_MARGIN);
		else
			player->y = collision.y - (TILE / 2 - COLLISION_MARGIN);
	}
	else if (y_diff < 0 && - y_diff < COLLISION_THRESHOLD && move_y != 0)
	{
		if (move_y < 0)
			player->y = collision.y - (TILE / 2 + COLLISION_MARGIN);
		else
			player->y = collision.y - (TILE / 2 - COLLISION_MARGIN);
	}
	else if (move_y != 0)
	{
		if (move_y > 0)
			player->y += COLLISION_THRESHOLD;
		else
			player->y -= COLLISION_THRESHOLD;
	}
}

t_point	calculate_new_pos(t_params *params)
{
	t_point	speed;
	t_point	new_pos;

	speed = calculate_speed(params);
	new_pos.x = params->player->x + speed.x;
	new_pos.y = params->player->y + speed.y;
	return (new_pos);
}

void	handle_wall_detection(t_params *params, t_map *map, t_point new_pos)
{
	t_point	move;
	t_point	pos;
	int		wall_detected;

	pos.x = new_pos.x + TILE / 2;
	pos.y = new_pos.y + TILE / 2;
	wall_detected = is_wall(map, pos.x / TILE, pos.y / TILE);
	if (wall_detected)
	{
		move.x = move_speed_x(params);
		move.y = move_speed_y(params);
		pos.x /= TILE;
		pos.y /= TILE;
		calculate_edge_coordinates(move, pos, &pos.x, &pos.y);
		adjust_x_position(params->player, move.x, pos, new_pos.x);
		adjust_y_position(params->player, move.y, pos, new_pos.y);
	}
	else
		move_player(params->player, move_speed_x(params), move_speed_y(params));
}
