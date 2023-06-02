/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:22 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:00:02 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Pas encore implémentée !
void	player_attack(t_images *images, t_params *params, t_player *player,
		t_map *map)
{
	int		frame_index_attack;
	void	*frame;

	frame_index_attack = 0;
	while (frame_index_attack != 7)
	{
		frame = images->player_attack[frame_index_attack];
		draw_map(map, params);
		mlx_put_image_to_window(params->mlx, params->mlx_win, frame, player->x,
			player->y);
		mlx_do_sync(params->mlx);
		frame_index_attack = (frame_index_attack + 1) % 8;
	}
}

void	player_eating(t_params *params, t_map *map)
{
	t_player	*player;
	int			collector_x;
	int			collector_y;

	player = params->player;
	collector_x = (player->x + TILE / 2) / TILE;
	collector_y = (player->y + TILE / 2) / TILE;
	if (map->data[collector_y][collector_x] == 'C')
	{
		map->data[collector_y][collector_x] = 'D';
		player->sushis_eaten++;
		if (player->sushis_eaten == 1)
			ft_printf(ITALIC""GREEN""SUSHI_MSG""RESET);
		else if (player->sushis_eaten == 2)
			ft_printf(BOLD""YELLOW""SUSHI_STATS_MSG""RESET,
				player->sushis_eaten);
		else if (player->sushis_eaten == 3)
			ft_printf(BOLD""YELLOW""SUSHI_EXPLO_MSG""RESET,
				player->sushis_eaten);
		else
		{
			ft_printf(BOLD""YELLOW""SUSHI_DUNG_MSG""RESET);
			player->is_death = 2;
		}
	}
}

void	update_player_movement(t_params *params, t_player *player)
{
	if (params->keys[KEY_LEFT])
	{
		player->is_flipped_horizontal = 1;
		player->left_moves++;
	}
	else if (params->keys[KEY_RIGHT])
	{
		player->is_flipped_horizontal = 0;
		player->right_moves++;
	}
	if (params->keys[KEY_UP])
		player->up_moves++;
	else if (params->keys[KEY_DOWN])
		player->down_moves++;
}

void	move_player(t_player *player, int move_x, int move_y)
{
	player->x += move_x;
	player->y += move_y;
}

void	update_player_position(t_params *params, t_map *map)
{
	t_point	new_pos;

	new_pos = calculate_new_pos(params);
	handle_wall_detection(params, map, new_pos);
	update_player_movement(params, params->player);
	player_eating(params, map);
	if (check_exit(params, map))
		restart_game(params, map);
}
