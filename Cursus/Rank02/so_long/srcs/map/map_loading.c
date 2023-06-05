/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:01:21 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:50:43 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_map_name(int level)
{
	char	*next_map_name;
	char	*level_str;

	next_map_name = (char *)ft_gc_malloc(20 * sizeof(char));
	if (!next_map_name)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	ft_bzero(next_map_name, 20);
	ft_strlcpy(next_map_name, "maps/Level", 11);
	level_str = ft_itoa(level + 1);
	ft_strlcat(next_map_name, level_str, 20);
	ft_strlcat(next_map_name, ".ber", 17);
	return (next_map_name);
}

char	*load_next_map(t_map *map)
{
	int		level;
	char	*next_map_name;
	int		fd;

	level = extract_level(map->filename);
	if (level < 0)
	{
		ft_printf(BOLD""RED""NEXT_LEVEL_NOT_FOUND""RESET, map->filename);
		return (NULL);
	}
	next_map_name = get_next_map_name(level);
	fd = open(next_map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	close(fd);
	return (next_map_name);
}
