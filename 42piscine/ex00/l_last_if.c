/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_first_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:29:41 by rrouille          #+#    #+#             */
/*   Updated: 2022/09/11 22:29:53 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_if_a(int **board, int **specificity, int **numbers, int i);
void	ft_if_b(int **board, int **specificity, int **numbers, int i);
void	ft_if_c(int **board, int **specificity, int **numbers, int i);
void	ft_if_d(int **board, int **specificity, int **numbers, int i);
void	ft_if_e(int **board, int **specificity, int **numbers, int i);
int		ft_search_missing(int **numbers, int n_ieme);
int		ft_missing_line(int **board, int map_size, int **numbers, int i);

void	ft_if_f(int **board, int **specificity, int **numbers, int i)
{
	if ((board[i][0] == 0) && (board[i][1] == 2) &&
		(board[i][2] == 4) && (board[i][3] == 0))
	{
		if (specificity[2][i] == 3)
		{
			board[i][0] = 1;
			board[i][3] = 3;
		}
		if (specificity[2][i] == 2)
		{
			board[i][0] = 3;
			board[i][3] = 1;
		}
	}
	if ((board[i][0] == 4) && (board[i][1] == 0) &&
			(board[i][2] == 1) && (board[i][3] == 0))
	{
		if (specificity[3][i] == 3)
		{
			board[i][1] = 3;
			board[i][3] = 2;
		}
	}
}

void	ft_if_g(int **board, int **specificity, int **numbers, int i)
{
	if ((board[i][0] == 0) && (board[i][1] == 1) &&
			(board[i][2] == 0) && (board[i][3] == 4))
	{
		if (specificity[2][i] == 3)
		{
			board[i][0] = 2;
			board[i][2] = 3;
		}
	}
	if ((board[i][0] == 4) && (board[i][1] == 1) &&
			(board[i][2] == 0) && (board[i][3] == 0))
	{
		board[i][2] = 2;
		board[i][3] = 3;
	}
	if ((board[i][0] == 0) && (board[i][1] == 0) &&
			(board[i][2] == 1) && (board[i][3] == 4))
	{
		board[i][0] = 3;
		board[i][1] = 2;
	}
}

void	ft_if_totals(int **board, int **specificity, int **numbers, int i)
{
	int	nb_zero;

	nb_zero = ft_missing_line(board, 4, numbers, i);
	if (nb_zero == 1)
	{
		board[i][numbers[1][0]] = ft_search_missing(numbers, 1);
	}
	else if (nb_zero == 2)
	{
		ft_if_a(board, specificity, numbers, i);
		ft_if_b(board, specificity, numbers, i);
		ft_if_c(board, specificity, numbers, i);
		ft_if_d(board, specificity, numbers, i);
		ft_if_e(board, specificity, numbers, i);
		ft_if_f(board, specificity, numbers, i);
		ft_if_g(board, specificity, numbers, i);
	}
}

void	ft_while_complet(int **board, int **specificity, int **numbers, int i)
{
	int	j;
	int	nb_zero;
	int	map_size;

	j = 0;
	map_size = 4;
	while (j < 4)
	{
		numbers[0][j] = j + 1;
		numbers[1][j] = -1;
		j++;
	}
	ft_if_totals(board, specificity, numbers, i);
}

void	ft_complett_line(int **board, int **specificity, int map_size)
{
	int	i;
	int	j;
	int	nb_zero;
	int	**numbers;

	numbers = malloc(sizeof(int *) * 2);
	numbers[0] = malloc(sizeof(int) * 4);
	numbers[1] = malloc(sizeof(int) * 4);
	i = -1;
	while (++i < map_size)
	{
		ft_while_complet(board, specificity, numbers, i);
	}
	free(numbers[0]);
	free(numbers[1]);
	free(numbers);
}
