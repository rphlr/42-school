/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:58:01 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 13:20:52 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	find_element_position(t_map *map, char element)
{
	t_point	position;
	int		i;
	int		j;

	position.x = -1;
	position.y = -1;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->data[i][j] == element)
			{
				position.x = j;
				position.y = i;
				return (position);
			}
		}
	}
	return (position);
}

int	count_sushis(t_map *map)
{
	int	x;
	int	y;
	int	sushi_count;

	sushi_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 'C')
				sushi_count++;
			x++;
		}
		y++;
	}
	return (sushi_count);
}
