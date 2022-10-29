/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:29:07 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 23:32:55 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	case1(int **board, int **specificity)
{
	if ((board[1][1] == 4) && (board[2][3] == 4)
			&& (specificity[1][1] == 2) && (specificity[2][2] == 3))
	{
		board[2][0] = 2;
		board[2][1] = 1;
		board[2][3] = 3;
	}
	if ((board[2][0] == 4) && (board[1][3] == 4)
			&& (specificity[1][2] == 2) && (specificity[3][2] == 3))
	{
		board[2][1] = 3;
		board[2][2] = 1;
		board[2][3] = 2;
	}
	if ((board[0][1] == 4) && (board[2][2] == 4)
			&& (specificity[2][2] == 2) && (specificity[1][1] == 3))
	{
		board[1][1] = 3;
		board[2][1] = 1;
		board[3][1] = 2;
	}
}

void	case2(int **board, int **specificity)
{
	if ((board[0][2] == 4) && (board[2][1] == 4)
			&& (specificity[3][2] == 2) && (specificity[1][2] == 3))
	{
		board[1][2] = 3;
		board[2][2] = 1;
		board[3][2] = 2;
	}
	if ((board[1][0] == 4) && (board[2][2] == 4)
			&& (specificity[0][2] == 2) && (specificity[3][1] == 3))
	{
		board[1][1] = 3;
		board[1][2] = 1;
		board[1][3] = 2;
	}
	if ((board[1][3] == 4) && (board[2][1] == 4)
			&& (specificity[0][1] == 2) && (specificity[2][1] == 3))
	{
		board[0][1] = 2;
		board[2][2] = 1;
		board[1][2] = 3;
	}
}

void	case3(int **board, int **specificity)
{
	if ((board[1][3] == 4) && (board[3][1] == 4)
			&& (specificity[2][1] == 2) && (specificity[0][2] == 3))
	{
		board[0][1] = 2;
		board[1][1] = 1;
		board[2][1] = 3;
	}
	if ((board[1][1] == 4) && (board[3][2] == 4)
			&& (specificity[3][1] == 2) && (specificity[0][3] == 3))
	{
		board[0][2] = 2;
		board[1][2] = 1;
		board[2][2] = 3;
	}
}

void	ft_place_one(int **board, int **specificity)
{
	case1(board, specificity);
	case2(board, specificity);
	case3(board, specificity);
}
