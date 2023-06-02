/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:12 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 10:12:20 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_map *map, t_params *params)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->data[i][j] == '1')
				draw_wall(params, i, j);
			else if (map->data[i][j] == '0' || map->data[i][j] == 'P'
					|| map->data[i][j] == 'W')
				draw_floor(params, i, j);
			else if (map->data[i][j] == 'C')
				draw_sushi(params, i, j);
			else if (map->data[i][j] == 'E')
				draw_exit(params, i, j);
			else if (map->data[i][j] == 'D')
				draw_dish(params, i, j);
		}
	}
}

void	draw_floor(t_params *params, int i, int j)
{
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->images->floor,
		j * TILE, i * TILE);
}

void	draw_wall(t_params *params, int i, int j)
{
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->images->wall,
		j * TILE, i * TILE);
}

void	draw_sushi(t_params *params, int i, int j)
{
	draw_floor(params, i, j);
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->images->sushi,
		j * TILE, i * TILE);
}

void	draw_dish(t_params *params, int i, int j)
{
	draw_floor(params, i, j);
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->images->dish,
		j * TILE, i * TILE);
}
