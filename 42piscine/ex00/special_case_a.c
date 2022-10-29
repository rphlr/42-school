/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:25:45 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 23:25:49 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	case_a1(int **board, int **specificity)
{
	if ((board[2][0] == 3) && (board[2][1] == 0)
			&& (board[2][2] == 0) && (board[2][3] == 4)
			&& (board[0][1] == 4) && (specificity[1][1] == 3))
	{
		board[2][1] = 1;
		board[2][2] = 2;
	}
	if ((board[2][0] == 3) && (board[2][1] == 0)
			&& (board[2][2] == 0) && (board[2][3] == 4)
			&& (board[0][2] == 4) && (specificity[1][2] == 3))
	{
		board[2][1] = 2;
		board[2][2] = 1;
	}
	if ((board[1][0] == 3) && (board[1][1] == 0)
			&& (board[1][2] == 0) && (board[1][3] == 4)
			&& (board[3][1] == 4) && (specificity[0][1] == 3))
	{
		board[1][1] = 1;
		board[1][2] = 2;
	}
}

void	case_a2(int **board, int **specificity)
{
	if ((board[1][0] == 3) && (board[1][1] == 0) &&
			(board[1][2] == 0) && (board[1][3] == 4)
			&& (board[3][2] == 4) && (specificity[0][2] == 3))
	{
		board[1][1] = 2;
		board[1][2] = 1;
	}
	if ((board[2][0] == 4) && (board[2][1] == 0)
			&& (board[2][2] == 0) && (board[2][3] == 3)
			&& (board[0][1] == 4) && (specificity[1][1] == 3))
	{
		board[2][1] = 1;
		board[2][2] = 2;
	}
	if ((board[2][0] == 4) && (board[2][1] == 0)
			&& (board[2][2] == 0) && (board[2][3] == 3)
			&& (board[0][2] == 4) && (specificity[1][2] == 3))
	{
		board[2][1] = 2;
		board[2][2] = 1;
	}
}

void	case_a3(int **board, int **specificity)
{
	if ((board[1][0] == 4) && (board[1][1] == 0)
			&& (board[1][2] == 0) && (board[1][3] == 3)
			&& (board[3][1] == 4) && (specificity[0][1] == 3))
	{
		board[1][1] = 1;
		board[1][2] = 2;
	}
	if ((board[1][0] == 4) && (board[1][1] == 0)
			&& (board[1][2] == 0) && (board[1][3] == 3)
			&& (board[3][2] == 4) && (specificity[0][2] == 3))
	{
		board[1][1] = 2;
		board[1][2] = 1;
	}
}
