/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:09 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:48:37 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_map_data(t_map *map, char *av)
{
	int		fd;
	char	*line;
	size_t	line_len;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	map->data = (char **)ft_gc_malloc(sizeof(char *) * map->height);
	if (!map->data)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	i = -1;
	while (++i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
		line_len = ft_strlen(line) - 1;
		while (line_len > 0 && (line[line_len] == '\n'
				|| line[line_len] == '\r'))
			line[line_len--] = '\0';
		map->data[i] = line;
	}
	close(fd);
	return (1);
}

int	set_map_size(t_map *map, char *av)
{
	int		fd;
	char	*line;
	int		line_len;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	line_len = ft_strlen(line);
	while (line_len > 0 && (line[line_len - 1] == '\n'
			|| line[line_len - 1] == '\r'))
		line_len--;
	map->width = line_len;
	if (!line || !(map->width))
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		map->height++;
	}
	close(fd);
	return (1);
}
