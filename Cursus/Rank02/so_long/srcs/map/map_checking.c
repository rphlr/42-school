/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 19:35:20 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_map *map)
{
	long unsigned int	width;
	int					i;

	i = -1;
	width = ft_strlen(map->data[0]);
	if (map == NULL || map->data == NULL || map->width <= 0 || map->height <= 0)
		return (0);
	while (++i < map->height)
	{
		if (ft_strlen(map->data[i]) != width)
			return (0);
	}
	return (1);
}

int	check_exit(t_params *params, t_map *map)
{
	char		*next_map_name;
	t_player	*player;
	int			exit_x;
	int			exit_y;
	int			sushi_count;

	player = params->player;
	exit_x = (player->x + TILE / 2) / TILE;
	exit_y = (player->y + TILE / 2) / TILE;
	sushi_count = count_sushis(map);
	if (map->data[exit_y][exit_x] != 'E' || sushi_count > 0)
		return (0);
	ft_printf(ITALIC""GREEN""VICTORY_MESSAGE""RESET);
	next_map_name = load_next_map(map);
	if (!next_map_name)
	{
		ft_printf(ITALIC""GREEN""GAME_FINISHED""RESET);
		close_window(params);
		return (1);
	}
	ft_printf(BLUE""NEXT_MAP_NAME""RESET, next_map_name);
	params->images->is_flipped = 0;
	params->in_game = 0;
	params->level_name = next_map_name;
	return (1);
}

void	check_enemy(t_params *params)
{
	t_player	*player;
	t_enemy		*enemy;
	t_point		player_pos;
	t_point		enemy_pos;
	t_point		diff;

	player = params->player;
	enemy = params->enemy;
	if (enemy == NULL)
		return ;
	player_pos.x = (player->x + TILE / 2) / TILE;
	player_pos.y = (player->y + TILE / 2) / TILE;
	enemy_pos.x = enemy->x / TILE;
	enemy_pos.y = enemy->y / TILE;
	diff.x = player_pos.x - enemy_pos.x;
	diff.y = player_pos.y - enemy_pos.y;
	if ((diff.x >= 0 && diff.x <= 1) && (diff.y >= 0 && diff.y <= 1))
	{
		ft_printf(BOLD""RED""DEATH_MESSAGE""RESET);
		params->player->is_death = 2;
	}
}

void	check_map(char *map_name)
{
	if (!check_map_name(map_name))
	{
		ft_printf(BOLD""RED""WRONG_MAP_NAME""RESET, map_name);
		exit(1);
	}
	if (!map_exists(map_name))
	{
		ft_printf(BOLD""RED""MAP_DOESNT_EXISTS""RESET, map_name);
		exit(1);
	}
}

t_map	*create_valid_map(char *map_name)
{
	t_map	*map;

	map = create_map(map_name);
	if (!is_map_valid(map))
	{
		ft_printf(BOLD""RED""MAP_NOT_VALID""RESET, map_name);
		exit(1);
	}
	return (map);
}
