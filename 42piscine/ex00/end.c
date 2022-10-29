/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:10:39 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 21:10:42 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_count(int **board, int search);

void	ft_end_prog(int **specificity, int **board, int **box, int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size)
	{
		free(board[i]);
		if (i < 3)
			free(box[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		free(specificity[i]);
		i++;
	}
	free(specificity);
	free(board);
	free(box);
}

int	ft_check_solve(int **board)
{
	if ((ft_count(board, 0) == 0) && (ft_count(board, 1) == 4)
		&& (ft_count(board, 2) == 4) && (ft_count(board, 3) == 4)
		&& (ft_count(board, 4) == 4))
		return (1);
	return (0);
}

void	ft_print_solve(int **board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 4)
	{
		c = board[i][0] + '0';
		write(1, &c, 1);
		write(1, " ", 1);
		c = board[i][1] + '0';
		write(1, &c, 1);
		write(1, " ", 1);
		c = board[i][2] + '0';
		write(1, &c, 1);
		write(1, " ", 1);
		c = board[i][3] + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
		i++;
	}
}
