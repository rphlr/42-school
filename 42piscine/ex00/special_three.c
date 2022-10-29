/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:34:14 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 23:37:21 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	case1q(int **board, int **specificity)
{
	if ((board[1][3] == 4) && (board[2][1] == 4)
			&& (specificity[0][1] == 3) && (specificity[2][1] == 3))
	{
		board[1][0] = 1;
		board[1][1] = 3;
		board[1][2] = 2;
	}
	if ((board[1][0] == 4) && (board[2][2] == 4)
			&& (specificity[0][2] == 3) && (specificity[3][1] == 3))
	{
		board[1][1] = 2;
		board[1][2] = 3;
		board[1][3] = 1;
	}
	if ((board[0][1] == 4) && (board[2][2] == 4)
			&& (specificity[1][1] == 3) && (specificity[2][2] == 3))
	{
		board[1][1] = 2;
		board[2][1] = 3;
		board[3][1] = 1;
	}
}

void	case2q(int **board, int **specificity)
{
	if ((board[0][2] == 4) && (board[2][1] == 4)
			&& (specificity[1][2] == 3) && (specificity[3][2] == 3))
	{
		board[1][2] = 2;
		board[2][2] = 1;
		board[3][2] = 3;
	}
	if ((board[1][1] == 4) && (board[3][2] == 4)
			&& (specificity[0][2] == 3) && (specificity[3][1] == 3))
	{
		board[0][2] = 1;
		board[1][2] = 3;
		board[2][2] = 2;
	}
	if ((board[3][1] == 4) && (board[1][2] == 4)
			&& (specificity[0][1] == 3) && (specificity[2][1] == 3))
	{
		board[0][1] = 1;
		board[1][1] = 3;
		board[2][1] = 2;
	}
}

void	case3q(int **board, int **specificity)
{
	if ((board[2][3] == 4) && (board[1][1] == 4)
			&& (specificity[1][1] == 3) && (specificity[2][2] == 3))
	{
		board[2][0] = 1;
		board[2][1] = 3;
		board[2][3] = 2;
	}
}

void	ft_special_three(int **board, int **specificity)
{
	case1q(board, specificity);
	case2q(board, specificity);
	case3q(board, specificity);
}
