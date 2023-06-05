/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:54:32 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 12:40:00 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_num_digits(int value)
{
	int	num_digits;

	num_digits = 1;
	while (value >= 10)
	{
		num_digits++;
		value /= 10;
	}
	return (num_digits);
}

char	*build_count_text(const char *text, int value)
{
	int		num_digits;
	int		text_len;
	int		index;
	char	*count_text;

	num_digits = get_num_digits(value);
	text_len = ft_strlen(text);
	count_text = ft_gc_malloc(text_len + num_digits + 1);
	if (count_text == NULL)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	ft_strcpy(count_text, text);
	index = text_len + num_digits;
	count_text[index--] = '\0';
	if (value == 0)
		count_text[index--] = (value % 10) + '0';
	while (value > 0)
	{
		count_text[index--] = (value % 10) + '0';
		value /= 10;
	}
	return (count_text);
}

int	extract_level(const char *filename)
{
	int			level;
	const char	*level_start = filename;

	level = 0;
	while (*level_start != '\0' && (*level_start < '0'
			|| *level_start > '9'))
	{
		++level_start;
	}
	if (*level_start == '\0')
	{
		return (-1);
	}
	while (*level_start >= '0' && *level_start <= '9')
	{
		level = level * 10 + (*level_start - '0');
		++level_start;
	}
	return (level);
}

void	calculate_edge_coordinates(t_point move, t_point collision,
			int *edge_x, int *edge_y)
{
	if (move.x > 0)
		*edge_x = (collision.x * TILE) + TILE - COLLISION_MARGIN;
	else
		*edge_x = (collision.x * TILE) + COLLISION_MARGIN;
	if (move.y > 0)
		*edge_y = (collision.y * TILE) + TILE - COLLISION_MARGIN;
	else
		*edge_y = (collision.y * TILE) + COLLISION_MARGIN;
}

t_point	calculate_speed(t_params *params)
{
	t_point	speed;

	speed.x = move_speed_x(params);
	speed.y = move_speed_y(params);
	return (speed);
}
