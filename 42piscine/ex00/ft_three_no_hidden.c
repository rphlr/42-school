/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_no_hidden.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:36:57 by rrouille          #+#    #+#             */
/*   Updated: 2022/09/11 13:37:03 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_no_hidden_box(int **board, int **specificity, int map_size)
{
	int	i;

	i = -1;
	while (i++ < map_size)
	{
		if (specificity[0][i] + specificity[1][i] == map_size + 1)
		{
			board[specificity[0][i] - 1][i] = map_size;
		}
		if (specificity[2][i] + specificity[3][i] == map_size + 1)
		{
			board[i][specificity[2][i] - 1] = map_size;
		}
	}
}

void	ft_three_complet(int **board, int **specificity, int map_size)
{
	int	i;

	i = -1;
	while (i++ < map_size)
	{
		if ((board[0][i] == 2) && (board[2][i] == 4))
		{
			if (specificity[0][i] == 3)
				board[1][i] = 3;
			if (specificity[0][i] == 2)
				board[1][i] = 1;
		}
		if ((board[3][i] == 2) && (board[1][i] == 4))
		{
			if (specificity[1][i] == 3)
				board[2][i] = 3;
			if (specificity[1][i] == 2)
				board[2][i] = 1;
		}
		if ((board[i][0] == 2) && (board[i][2] == 4))
		{
			if (specificity[2][i] == 3)
				board[i][1] = 3;
			if (specificity[2][i] == 2)
				board[i][1] = 1;
		}
		if ((board[i][3] == 2) && (board[i][1] == 4))
		{
			if (specificity[3][i] == 3)
				board[i][2] = 3;
			if (specificity[3][i] == 2)
				board[i][2] = 1;
		}
	}
}
