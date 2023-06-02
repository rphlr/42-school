/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:19 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:46:29 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_player_enemy_frames(t_params *params, void *player_frame,
		void *enemy_frame)
{
	t_player	*player;
	t_enemy		*enemy;

	player = params->player;
	enemy = params->enemy;
	mlx_put_image_to_window(params->mlx, params->mlx_win, player_frame,
		player->x, player->y);
	if (enemy != NULL)
		mlx_put_image_to_window(params->mlx, params->mlx_win, enemy_frame,
			enemy->x, enemy->y);
	mlx_do_sync(params->mlx);
	mlx_clear_window(params->mlx, params->mlx_win);
}

void	display_game_info(t_params *params, t_map *map,
	void *player_frame, void *enemy_frame)
{
	char	*level;

	level = ft_strjoin("Map : ", map->filename);
	display_move_count(params, params->player);
	display_meal_count(params, params->player);
	mlx_string_put(params->mlx, params->mlx_win, ((map->width * TILE) / 2)
		- 75, 15, 0xFFFFFF, level);
	display_player_enemy_frames(params, player_frame, enemy_frame);
}

void	display_move_count(t_params *params, t_player *player)
{
	int		total_moves;
	char	*move_count_text;
	int		text_x;
	int		text_y;

	total_moves = player->left_moves + player->right_moves + player->up_moves
		+ player->down_moves;
	move_count_text = build_count_text(MOVE_COUNT_TEXT, total_moves);
	text_x = 15;
	text_y = 30;
	mlx_string_put(params->mlx, params->mlx_win, text_x, text_y, 0xFFFFFF,
		move_count_text);
}

void	display_meal_count(t_params *params, t_player *player)
{
	int		total_meals;
	char	*meal_count_text;
	int		text_x;
	int		text_y;

	total_meals = player->sushis_eaten;
	meal_count_text = build_count_text(MEAL_COUNT_TEXT, total_meals);
	text_x = 15;
	text_y = 40;
	mlx_string_put(params->mlx, params->mlx_win, text_x, text_y, 0xFFFFFF,
		meal_count_text);
}
