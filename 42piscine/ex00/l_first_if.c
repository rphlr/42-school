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

int		ft_search_missing(int **numbers, int n_ieme);
int		ft_missing_line(int **board, int map_size, int **numbers, int i);
void	ft_if_f(int **board, int **specificity, int **numbers, int i);
void	ft_if_g(int **board, int **specificity, int **numbers, int i);
void	ft_if_totals(int **board, int **specificity, int **numbers, int i);
void	ft_while_complet(int **board, int **specificity, int **numbers, int i);

void	ft_if_a(int **board, int **specificity, int **numbers, int i)
{
	if ((board[i][0] == 0) && (board[i][1] == 0) && (board[i][2] == 4))
	{
		if (specificity[2][i] == 3)
		{
			board[i][0] = ft_search_missing(numbers, 1);
			board[i][1] = ft_search_missing(numbers, 2);
		}
		else if (specificity[2][i] == 2)
		{
			board[i][0] = ft_search_missing(numbers, 2);
			board[i][1] = ft_search_missing(numbers, 1);
		}
	}
}

void	ft_if_b(int **board, int **specificity, int **numbers, int i)
{
	if ((board[i][3] == 0) && (board[i][2] == 0) && (board[i][1] == 4))
	{
		if (specificity[3][i] == 3)
		{
			board[i][3] = ft_search_missing(numbers, 1);
			board[i][2] = ft_search_missing(numbers, 2);
		}
		else if (specificity[3][i] == 2)
		{
			board[i][3] = ft_search_missing(numbers, 2);
			board[i][2] = ft_search_missing(numbers, 1);
		}
	}
}

void	ft_if_c(int **board, int **specificity, int **numbers, int i)
{
	if ((board[i][0] == 0) && (board[i][1] == 0) &&
			(board[i][2] == 4) && (board[i][3] == 3))
	{
		board[i][1] = 1;
		board[i][0] = 2;
	}
	if ((board[i][0] == 3) && (board[i][1] == 4) &&
			(board[i][2] == 0) && (board[i][3] == 0))
	{
		board[i][2] = 1;
		board[i][3] = 2;
	}
	if ((board[i][0] == 0) && (board[i][1] == 0) &&
			(board[i][2] == 3) && (board[i][3] == 4))
	{
		board[i][1] = 1;
		board[i][0] = 2;
	}
}

void	ft_if_d(int **board, int **specificity, int **numbers, int i)
{
	if ((board[i][0] == 4) && (board[i][1] == 3) &&
			(board[i][2] == 0) && (board[i][3] == 0))
	{
		board[i][2] = 1;
		board[i][3] = 2;
	}
	if ((board[i][0] == 0) && (board[i][1] == 0) &&
			(board[i][2] == 2) && (board[i][3] == 4))
	{
		if (specificity[2][i] == 3)
		{
			board[i][1] = 3;
			board[i][0] = 1;
		}
	}
	if ((board[i][0] == 4) && (board[i][1] == 2) &&
			(board[i][2] == 0) && (board[i][3] == 0))
	{
		if (specificity[3][i] == 3)
		{
			board[i][2] = 3;
			board[i][3] = 1;
		}
	}
}

void	ft_if_e(int **board, int **specificity, int **numbers, int i)
{
	if ((board[i][0] == 0) && (board[i][1] == 4) &&
			(board[i][2] == 2) && (board[i][3] == 0))
	{
		if (specificity[3][i] == 3)
		{
			board[i][0] = 3;
			board[i][3] = 1;
		}
		if (specificity[3][i] == 2)
		{
			board[i][0] = 1;
			board[i][3] = 3;
		}
	}
}
