/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:19 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:48:09 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*create_map(char *av)
{
	t_map	*map;

	map = (t_map *)ft_gc_malloc(sizeof(t_map));
	if (!map)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	map->width = 0;
	map->height = 1;
	map->filename = ft_strdup(av);
	if (!map->filename)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	if (!set_map_size(map, av))
		return (NULL);
	if (!set_map_data(map, av))
		return (NULL);
	ft_printf(ITALIC""GREEN""FILENAME""RESET, av);
	return (map);
}

int	is_closed_by_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		if (i == 0 || i == map->height - 1)
		{
			j = -1;
			while (++j < map->width - 1)
			{
				if (map->data[i][j] != '1')
					return (0);
			}
		}
		else
		{
			if (map->data[i][0] != '1' || map->data[i][map->width - 1] != '1')
				return (0);
		}
	}
	return (1);
}

int	has_valid_elements(t_map *map, int start, int exit, int collectibles)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			c = map->data[i][j];
			if (c == 'P')
				start++;
			else if (c == 'E')
				exit++;
			else if (c == 'C')
				collectibles++;
			else if (c != '0' && c != '1' && c != 'W')
				return (0);
		}
	}
	return (start == 1 && exit == 1 && collectibles >= 1);
}

int	is_path_valid(t_map *map)
{
	char	**temp_map;
	int		i;
	int		path_valid;
	t_point	start;
	t_point	end;

	temp_map = ft_gc_malloc(sizeof(char *) * map->height);
	if (!temp_map)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	i = -1;
	while (++i < map->height)
		temp_map[i] = ft_strdup(map->data[i]);
	start = find_element_position(map, 'P');
	end = find_element_position(map, 'E');
	flood_fill(temp_map, (t_point){map->width, map->height}, start);
	path_valid = (temp_map[end.y][end.x] == 'F');
	i = -1;
	return (path_valid);
}

int	is_map_valid(t_map *map)
{
	int	start;
	int	exit;
	int	collectibles;

	if (!is_rectangle(map) || !is_closed_by_walls(map))
	{
		ft_printf(BOLD""RED""NOT_CLOSED_WALL""RESET);
		return (0);
	}
	start = 0;
	exit = 0;
	collectibles = 0;
	if (!has_valid_elements(map, start, exit, collectibles))
	{
		ft_printf(BOLD""RED""ELEMENTS_NOT_VALID""RESET);
		return (0);
	}
	if (!is_path_valid(map))
	{
		ft_printf(BOLD""RED""PATH_NOT_VALID""RESET);
		return (0);
	}
	return (1);
}
