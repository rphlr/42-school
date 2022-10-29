/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:26:50 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 23:26:52 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	case_b1(int **board, int **specificity)
{
	if ((board[0][2] == 3) && (board[1][2] == 0)
			&& (board[2][2] == 0) && (board[3][2] == 4)
			&& (board[1][0] == 4) && (specificity[3][1] == 3))
	{
		board[1][2] = 1;
		board[2][2] = 2;
	}
	if ((board[0][2] == 3) && (board[1][2] == 0)
			&& (board[2][2] == 0) && (board[3][2] == 4)
			&& (board[2][0] == 4) && (specificity[3][2] == 3))
	{
		board[1][2] = 2;
		board[2][2] = 1;
	}
	if ((board[0][1] == 3) && (board[1][1] == 0)
			&& (board[2][1] == 0) && (board[3][1] == 4)
			&& (board[1][3] == 4) && (specificity[2][1] == 3))
	{
		board[1][1] = 1;
		board[2][1] = 2;
	}
}

void	case_b2(int **board, int **specificity)
{
	if ((board[0][1] == 3) && (board[1][1] == 0)
			&& (board[2][1] == 0) && (board[3][1] == 4)
			&& (board[2][3] == 4) && (specificity[2][2] == 3))
	{
		board[1][1] = 2;
		board[2][1] = 1;
	}
	if ((board[0][2] == 4) && (board[1][2] == 0)
			&& (board[2][2] == 0) && (board[3][2] == 3)
			&& (board[1][0] == 4) && (specificity[3][1] == 3))
	{
		board[1][2] = 1;
		board[2][2] = 2;
	}
	if ((board[0][2] == 4) && (board[1][2] == 0)
			&& (board[2][2] == 0) && (board[3][2] == 3)
			&& (board[2][0] == 4) && (specificity[3][2] == 3))
	{
		board[1][2] = 2;
		board[2][2] = 1;
	}
}

void	case_b3(int **board, int **specificity)
{
	if ((board[0][1] == 4) && (board[1][1] == 0)
			&& (board[2][1] == 0) && (board[3][1] == 3)
			&& (board[1][3] == 4) && (specificity[2][1] == 3))
	{
		board[1][1] = 1;
		board[2][1] = 2;
	}
	if ((board[0][1] == 4) && (board[1][1] == 0)
			&& (board[2][1] == 0) && (board[3][1] == 3)
			&& (board[2][3] == 4) && (specificity[2][2] == 3))
	{
		board[1][1] = 2;
		board[2][1] = 1;
	}
}
