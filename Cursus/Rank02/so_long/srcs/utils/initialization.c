/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:53 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 19:11:22 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_structures(t_params *params, t_map *map, t_images *images)
{
	params->bg_img = init_background_image(params);
	params->mlx_win = mlx_new_window(params->mlx, map->width * TILE, map->height
			* TILE, PROG_NAME);
	params->player = find_player_position(map);
	params->enemy = find_enemy_position(map);
	load_images(params, images);
	params->images = images;
	params->buffer = mlx_new_image(params->mlx, map->width * TILE, map->height
			* TILE);
	params->images->addr = mlx_get_data_addr(params->buffer,
			&params->images->bits_per_pixel, &params->images->line_length,
			&params->images->endian);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf(BOLD""YELLOW""ARGS""RESET, av[0]);
		return (0);
	}
	run_game(av[1]);
	return (0);
}

void	handle_window_close(t_params *params)
{
	close_window(params);
}
