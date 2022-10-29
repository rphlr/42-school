/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:27:46 by rrouille          #+#    #+#             */
/*   Updated: 2022/09/11 22:28:26 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_if_last(int **board, int find, int search, int line)
{
	int	i;
	int	j;

	if (find == 0)
	{
		find = 1;
		i = 0;
		while (i < 4 && find)
		{
			find = 0;
			j = 0;
			while (j < 4 && !find)
			{
				if (board[j][i] == search)
					find = 1;
				j++;
			}
			if (!find)
				board[line][i] = search;
			i++;
		}
	}
}

void	ft_last(int **board, int search)
{
	int	find;
	int	i;
	int	j;
	int	line;

	i = 0;
	find = 1;
	while (i < 4 && find)
	{
		find = 0;
		j = 0;
		while (j < 4 && !find)
		{
			if (board[i][j] == search)
				find = 1;
			j++;
		}
		if (!find)
			line = i;
		i++;
	}
	ft_if_last(board, find, search, line);
}
