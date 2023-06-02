/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:27 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:45:58 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = ft_gc_malloc(sizeof(t_player));
	if (player == NULL)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	player->state = 0;
	player->is_death = 0;
	player->sushis_eaten = 0;
	player->left_moves = 0;
	player->right_moves = 0;
	player->up_moves = 0;
	player->down_moves = 0;
	player->num_resurrections = 0;
	return (player);
}

void	set_player_position(t_player *player, int i, int j)
{
	player->x = j * TILE;
	player->y = i * TILE;
	player->prev_x = player->x;
	player->prev_y = player->y;
}

t_player	*find_player_position(t_map *map)
{
	t_player	*player;
	int			i;
	int			j;

	player = init_player();
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->data[i][j] == 'P')
			{
				set_player_position(player, i, j);
				return (player);
			}
		}
	}
	return (NULL);
}

void	*player_resurrect(t_images *images, t_params *params, t_player *player,
		t_map *map)
{
	int		frame_index_death;
	void	*frame;

	frame_index_death = 8;
	player->num_resurrections++;
	if (player->num_resurrections == 3)
	{
		ft_printf(BOLD""RED""PLAYER_LOSER_MSG""RESET);
		close_window(params);
	}
	while (frame_index_death > 0)
	{
		frame = images->player_death[frame_index_death];
		draw_map(map, params);
		mlx_put_image_to_window(params->mlx, params->mlx_win, frame, player->x,
			player->y);
		mlx_do_sync(params->mlx);
		frame_index_death--;
	}
	player->is_death = 0;
	return (frame);
}

void	*player_death(t_images *images, t_params *params, t_player *player,
		t_map *map)
{
	int		frame_index_death;
	void	*frame;

	frame_index_death = 0;
	while (frame_index_death < 9)
	{
		frame = images->player_death[frame_index_death];
		draw_map(map, params);
		mlx_put_image_to_window(params->mlx, params->mlx_win, frame, player->x,
			player->y);
		mlx_do_sync(params->mlx);
		frame_index_death++;
	}
	player->is_death = 1;
	return (frame);
}
