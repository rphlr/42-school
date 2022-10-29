/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:11:21 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 21:11:36 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_init_tab(int **specificity, int **board, int **box, int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size)
	{
		board[i] = malloc(sizeof(int) * map_size);
		box[i] = malloc(sizeof(int) * 3);
		j = 0;
		while (++j < map_size)
		{
			board[i][j] = 0;
			if (i < 3)
				box[i][j] = 0;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		specificity[i] = malloc(sizeof(int) * map_size);
		i++;
	}
}

int	ft_initial_control(int argc, char **argv, int map_size, int **specificity)
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0)
		{
			if (argv[1][i] < '1' || argv[1][i] > (map_size + '0'))
				return (0);
			specificity[(i / 2) / map_size][(i / 2) % map_size] \
				= (argv[1][i] - '0');
		}
		else if (i % 2 == 1)
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i++;
	}
	if (i != map_size *(4 * 2) - 1)
		return (0);
	return (1);
}

int	ft_sum_control(int map_size, int **specificity)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		if ((specificity[0][i] + specificity[1][i]) > (map_size + 1))
			return (0);
		if ((specificity[2][i] + specificity[3][i]) > (map_size + 1))
			return (0);
		i++;
	}
	return (1);
}
