/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:33 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:49:23 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*init_enemy(void)
{
	t_enemy	*enemy;

	enemy = ft_gc_malloc(sizeof(t_enemy));
	if (enemy == NULL)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	enemy->move_speed = ENEMY_MOVE_SPEED;
	return (enemy);
}

void	set_enemy_position(t_enemy *enemy, int i, int j)
{
	enemy->x = j * TILE;
	enemy->y = i * TILE;
	enemy->destination_x = enemy->x;
	enemy->destination_y = enemy->y;
}

t_enemy	*find_enemy_position(t_map *map)
{
	t_enemy	*enemy;
	int		i;
	int		j;

	enemy = init_enemy();
	if (enemy == NULL)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->data[i][j] == 'W')
			{
				set_enemy_position(enemy, i, j);
				return (enemy);
			}
		}
	}
	return (NULL);
}

void	process_enemy_state(t_process_enemy_state_params *params)
{
	t_enemy		*enemy;
	t_images	*images;

	enemy = params->params->enemy;
	images = params->images;
	if (enemy->state == 0)
	{
		*params->enemy_frame
			= images->enemy_idle[*params->frame_index_enemy_idle];
		*params->frame_index_enemy_idle = (*params->frame_index_enemy_idle + 1)
			% params->n_idle_frames;
	}
	else if (enemy->state == 1)
	{
		*params->enemy_frame
			= images->enemy_run[*params->frame_index_enemy_run];
		*params->frame_index_enemy_run = (*params->frame_index_enemy_run + 1)
			% params->n_run_frames;
	}
}

void	update_enemy_position(t_params *params, t_map *map, t_enemy *enemy)
{
	if (enemy == NULL)
		return ;
	update_enemy_destination(enemy);
	check_enemy_wall_collision(map, enemy);
	move_enemy(enemy);
	if (params->player->is_death < 1)
		check_enemy(params);
}
