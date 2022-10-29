/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:36:21 by rrouille          #+#    #+#             */
/*   Updated: 2022/09/11 13:36:24 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_missing_colomn(int **board, int map_size, int **numbers, int i);
int	ft_missing_line(int **board, int map_size, int **numbers, int i);
int	ft_search_missing(int **numbers, int n_ieme);

void	ft_case_min_max(int **board, int **specificity, int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size)
	{
		if (specificity[0][i] == 1)
		{
			board[0][i] = map_size;
			if (specificity[1][i] == 2)
				board[3][i] = 3;
		}
		if (specificity[1][i] == 1)
		{
			board[3][i] = map_size;
			if (specificity[0][i] == 2)
				board[0][i] = 3;
		}
		if (specificity[2][i] == 1)
		{
			board[i][0] = map_size;
			if (specificity[3][i] == 2)
				board[i][3] = 3;
		}
		if (specificity[3][i] == 1)
		{
			board[i][3] = map_size;
			if (specificity[2][i] == 2)
				board[i][0] = 3;
		}
		if (specificity[0][i] == map_size)
		{
			j = -1;
			while (j++ < map_size)
				board[j][i] = j + 1;
		}
		if (specificity[1][i] == map_size)
		{
			j = -1;
			while (++j < map_size)
				board[(map_size - 1) - j][i] = j + 1;
		}
		if (specificity[2][i] == map_size)
		{
			j = -1;
			while (++j < map_size)
				board[i][j] = j + 1;
		}
		if (specificity[3][i] == map_size)
		{
			j = -1;
			while (++j < map_size)
				board[i][(map_size - 1) - j] = j + 1;
		}
		i++;
	}
}

void	ft_decide_columns(int **board)
{
	int	**numbers;
	int	**numbers2;
	int i;
	int j;
	int line1;

	numbers = malloc(sizeof(int *) * 2);
	numbers[0] = malloc(sizeof(int) * 4);
	numbers[1] = malloc(sizeof(int) * 4);
	numbers2 = malloc(sizeof(int *) * 2);
	numbers2[0] = malloc(sizeof(int) * 4);
	numbers2[1] = malloc(sizeof(int) * 4);
	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			numbers[0][j] = j + 1;
			numbers[1][j] = -1;
			j++;
		}
		if (ft_missing_colomn(board, 4, numbers, i) == 2)
			break ;
	}
	line1 = i;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			numbers2[0][j] = j + 1;
			numbers2[1][j] = -1;
			j++;
		}
		if (ft_missing_colomn(board, 4, numbers2, i) == 2)
			break ;
	}
	
	if (line1 != i)
	{
		if ((numbers[1][0] == numbers2[1][0]) && (numbers[1][1] == numbers2[1][1]))
		{
			if ((ft_search_missing(numbers, 1) == ft_search_missing(numbers2, 1)) && (ft_search_missing(numbers, 2) == ft_search_missing(numbers2, 2)))
				board[numbers[1][0]][line1] = ft_search_missing(numbers, 1);
		}
	}
}

void	ft_decide_lines(int **board)
{
	int	**numbers;
	int	**numbers2;
	int i;
	int j;
	int line1;

	numbers = malloc(sizeof(int *) * 2);
	numbers[0] = malloc(sizeof(int) * 4);
	numbers[1] = malloc(sizeof(int) * 4);
	numbers2 = malloc(sizeof(int *) * 2);
	numbers2[0] = malloc(sizeof(int) * 4);
	numbers2[1] = malloc(sizeof(int) * 4);
	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			numbers[0][j] = j + 1;
			numbers[1][j] = -1;
			j++;
		}
		if (ft_missing_line(board, 4, numbers, i) == 2)
			break ;
	}
	line1 = i;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			numbers2[0][j] = j + 1;
			numbers2[1][j] = -1;
			j++;
		}
		if (ft_missing_line(board, 4, numbers2, i) == 2)
			break ;
	}
	
	if (line1 != i)
	{
		//printf("%d - %d\n", line1, numbers[1][0]);
		if ((numbers[1][0] == numbers2[1][0]) && (numbers[1][1] == numbers2[1][1]))
		{
			//printf("%d-%d %d-%d\n", ft_search_missing(numbers, 1), ft_search_missing(numbers2, 1), ft_search_missing(numbers, 2), ft_search_missing(numbers2, 2));
			if ((ft_search_missing(numbers, 1) == ft_search_missing(numbers2, 1)) && (ft_search_missing(numbers, 2) == ft_search_missing(numbers2, 2)))
				board[line1][numbers[1][0]] = ft_search_missing(numbers, 1);
		}
	}
	
}

void	ft_special_case(int **board, int **specificity)
{
	if ((board[2][0] == 3) && (board[2][1] == 0) && (board[2][2] == 0) && (board[2][3] == 4) && (board[0][1] == 4) && (specificity[1][1] == 3))
	{
		board[2][1] = 1;
		board[2][2] = 2;
	}
	if ((board[2][0] == 3) && (board[2][1] == 0) && (board[2][2] == 0) && (board[2][3] == 4) && (board[0][2] == 4) && (specificity[1][2] == 3))
	{
		board[2][1] = 2;
		board[2][2] = 1;
	}
	if ((board[1][0] == 3) && (board[1][1] == 0) && (board[1][2] == 0) && (board[1][3] == 4) && (board[3][1] == 4) && (specificity[0][1] == 3))
	{
		board[1][1] = 1;
		board[1][2] = 2;
	}
	if ((board[1][0] == 3) && (board[1][1] == 0) && (board[1][2] == 0) && (board[1][3] == 4) && (board[3][2] == 4) && (specificity[0][2] == 3))
	{
		board[1][1] = 2;
		board[1][2] = 1;
	}

	if ((board[2][0] == 4) && (board[2][1] == 0) && (board[2][2] == 0) && (board[2][3] == 3) && (board[0][1] == 4) && (specificity[1][1] == 3))
	{
		board[2][1] = 1;
		board[2][2] = 2;
	}
	if ((board[2][0] == 4) && (board[2][1] == 0) && (board[2][2] == 0) && (board[2][3] == 3) && (board[0][2] == 4) && (specificity[1][2] == 3))
	{
		board[2][1] = 2;
		board[2][2] = 1;
	}
	if ((board[1][0] == 4) && (board[1][1] == 0) && (board[1][2] == 0) && (board[1][3] == 3) && (board[3][1] == 4) && (specificity[0][1] == 3))
	{
		board[1][1] = 1;
		board[1][2] = 2;
	}
	if ((board[1][0] == 4) && (board[1][1] == 0) && (board[1][2] == 0) && (board[1][3] == 3) && (board[3][2] == 4) && (specificity[0][2] == 3))
	{
		board[1][1] = 2;
		board[1][2] = 1;
	}
	


	if ((board[0][2] == 3) && (board[1][2] == 0) && (board[2][2] == 0) && (board[3][2] == 4) && (board[1][0] == 4) && (specificity[3][1] == 3))
	{
		board[1][2] = 1;
		board[2][2] = 2;
	}
	if ((board[0][2] == 3) && (board[1][2] == 0) && (board[2][2] == 0) && (board[3][2] == 4) && (board[2][0] == 4) && (specificity[3][2] == 3))
	{
		board[1][2] = 2;
		board[2][2] = 1;
	}
	if ((board[0][1] == 3) && (board[1][1] == 0) && (board[2][1] == 0) && (board[3][1] == 4) && (board[1][3] == 4) && (specificity[2][1] == 3))
	{
		board[1][1] = 1;
		board[2][1] = 2;
	}
	if ((board[0][1] == 3) && (board[1][1] == 0) && (board[2][1] == 0) && (board[3][1] == 4) && (board[2][3] == 4) && (specificity[2][2] == 3))
	{
		board[1][1] = 2;
		board[2][1] = 1;
	}

	if ((board[0][2] == 4) && (board[1][2] == 0) && (board[2][2] == 0) && (board[3][2] == 3) && (board[1][0] == 4) && (specificity[3][1] == 3))
	{
		board[1][2] = 1;
		board[2][2] = 2;
	}
	if ((board[0][2] == 4) && (board[1][2] == 0) && (board[2][2] == 0) && (board[3][2] == 3) && (board[2][0] == 4) && (specificity[3][2] == 3))
	{
		board[1][2] = 2;
		board[2][2] = 1;
	}
	if ((board[0][1] == 4) && (board[1][1] == 0) && (board[2][1] == 0) && (board[3][1] == 3) && (board[1][3] == 4) && (specificity[2][1] == 3))
	{
		board[1][1] = 1;
		board[2][1] = 2;
	}
	if ((board[0][1] == 4) && (board[1][1] == 0) && (board[2][1] == 0) && (board[3][1] == 3) && (board[2][3] == 4) && (specificity[2][2] == 3))
	{
		board[1][1] = 2;
		board[2][1] = 1;
	}
}

void	ft_place_one(int **board, int **specificity)
{
	if ((board[1][1] == 4) && (board[2][3] == 4) && (specificity[1][1] == 2) && (specificity[2][2] == 3))
	{
		board[2][0] = 2;
		board[2][1] = 1;
		board[2][3] = 3;
	}
	if ((board[2][0] == 4) && (board[1][3] == 4) && (specificity[1][2] == 2) && (specificity[3][2] == 3))
	{
		board[2][1] = 3;
		board[2][2] = 1;
		board[2][3] = 2;
	}

	if ((board[0][1] == 4) && (board[2][2] == 4) && (specificity[2][2] == 2) && (specificity[1][1] == 3))
	{
		board[1][1] = 3;
		board[2][1] = 1;
		board[3][1] = 2;
	}
	if ((board[0][2] == 4) && (board[2][1] == 4) && (specificity[3][2] == 2) && (specificity[1][2] == 3))
	{
		board[1][2] = 3;
		board[2][2] = 1;
		board[3][2] = 2;
	}

	if ((board[1][0] == 4) && (board[2][2] == 4) && (specificity[0][2] == 2) && (specificity[3][1] == 3))
	{
		board[1][1] = 3;
		board[1][2] = 1;
		board[1][3] = 2;
	}
	if ((board[1][3] == 4) && (board[2][1] == 4) && (specificity[0][1] == 2) && (specificity[2][1] == 3))
	{
		board[0][1] = 2;
		board[2][2] = 1;
		board[1][2] = 3;
	}

	if ((board[1][3] == 4) && (board[3][1] == 4) && (specificity[2][1] == 2) && (specificity[0][2] == 3))
	{
		board[0][1] = 2;
		board[1][1] = 1;
		board[2][1] = 3;
	}
	if ((board[1][1] == 4) && (board[3][2] == 4) && (specificity[3][1] == 2) && (specificity[0][3] == 3))
	{
		board[0][2] = 2;
		board[1][2] = 1;
		board[2][2] = 3;
	}
}

void	ft_special_three(int **board, int **specificity)
{
	if ((board[1][3] == 4) && (board[2][1] == 4) && (specificity[0][1] == 3) && (specificity[2][1] == 3))
	{
		board[1][0] = 1;
		board[1][1] = 3;
		board[1][2] = 2;
	}
	if ((board[1][0] == 4) && (board[2][2] == 4) && (specificity[0][2] == 3) && (specificity[3][1] == 3))
	{
		board[1][1] = 2;
		board[1][2] = 3;
		board[1][3] = 1;
	}

	if ((board[0][1] == 4) && (board[2][2] == 4) && (specificity[1][1] == 3) && (specificity[2][2] == 3))
	{
		board[1][1] = 2;
		board[2][1] = 3;
		board[3][1] = 1;
	}
	if ((board[0][2] == 4) && (board[2][1] == 4) && (specificity[1][2] == 3) && (specificity[3][2] == 3))
	{
		board[1][2] = 2;
		board[2][2] = 1;
		board[3][2] = 3;
	}

	if ((board[1][1] == 4) && (board[3][2] == 4) && (specificity[0][2] == 3) && (specificity[3][1] == 3))
	{
		board[0][2] = 1;
		board[1][2] = 3;
		board[2][2] = 2;
	}

	if ((board[3][1] == 4) && (board[1][2] == 4) && (specificity[0][1] == 3) && (specificity[2][1] == 3))
	{
		board[0][1] = 1;
		board[1][1] = 3;
		board[2][1] = 2;
	}
	if ((board[2][3] == 4) && (board[1][1] == 4) && (specificity[1][1] == 3) && (specificity[2][2] == 3))
	{
		board[2][0] = 1;
		board[2][1] = 3;
		board[2][3] = 2;
	}
}

void	ft_special_one(int **board, int **specificity)
{
	if ((board[1][3] == 4) && (board[2][1] == 4) && (specificity[0][1] == 2) && (specificity[2][1] == 3))
	{
		board[1][0] = 2;
		board[1][1] = 1;
		board[1][2] = 3;
	}
	if ((board[1][0] == 4) && (board[2][2] == 4) && (specificity[0][2] == 2) && (specificity[3][1] == 3))
	{
		board[1][1] = 3;
		board[1][2] = 1;
		board[1][3] = 2;
	}

	if ((board[0][1] == 4) && (board[2][2] == 4) && (specificity[1][1] == 3) && (specificity[2][2] == 2))
	{
		board[1][1] = 3;
		board[2][1] = 1;
		board[3][1] = 2;
	}
	if ((board[0][2] == 4) && (board[2][1] == 4) && (specificity[1][2] == 3) && (specificity[3][2] == 2))
	{
		board[1][2] = 3;
		board[2][2] = 1;
		board[3][2] = 2;
	}

	if ((board[1][1] == 4) && (board[3][2] == 4) && (specificity[0][2] == 3) && (specificity[3][1] == 2))
	{
		board[0][2] = 2;
		board[1][2] = 1;
		board[2][2] = 3;
	}

	if ((board[3][1] == 4) && (board[1][2] == 4) && (specificity[0][1] == 3) && (specificity[2][1] == 2))
	{
		board[0][1] = 2;
		board[1][1] = 1;
		board[2][1] = 3;
	}
	if ((board[2][3] == 4) && (board[1][1] == 4) && (specificity[1][1] == 2) && (specificity[2][2] == 3))
	{
		board[2][0] = 2;
		board[2][1] = 1;
		board[2][3] = 3;
	}
}

void	ft_magic_for(int **board, int **specificity)
{
	if ((board[0][3] == 4) && (board[2][1] == 4) && (specificity[0][1] == 2) && (specificity[2][0] == 3))
		board[0][1] = 3;
	if ((board[3][0] == 4) && (board[1][2] == 4) && (specificity[1][2] == 2) && (specificity[3][3] == 3))
		board[3][2] = 3;
	if ((board[0][0] == 4) && (board[2][2] == 4) && (specificity[2][2] == 2) && (specificity[1][0] == 3))
		board[2][0] = 3;
	if ((board[1][1] == 4) && (board[3][3] == 4) && (specificity[3][1] == 2) && (specificity[0][3] == 3))
		board[1][3] = 3;
	if ((board[0][3] == 4) && (board[2][1] == 4) && (specificity[3][2] == 2) && (specificity[1][3] == 3))
		board[2][3] = 3;
	if ((board[3][0] == 4) && (board[1][2] == 4) && (specificity[2][1] == 2) && (specificity[0][0] == 3))
		board[1][0] = 3;
	if ((board[0][0] == 4) && (board[2][2] == 4) && (specificity[0][2] == 2) && (specificity[3][0] == 3))
		board[0][2] = 3;
	if ((board[1][1] == 4) && (board[3][3] == 4) && (specificity[1][1] == 2) && (specificity[2][3] == 3))
		board[3][1] = 3;
}

void	ft_magic_two(int **board, int **specificity)
{
	if ((board[1][2] == 4) && (board[2][1] == 4 && (board[0][1] == 3) && specificity[2][1] == 3))
		board[1][1] = 2;
	if ((board[1][2] == 4) && (board[2][1] == 4 && (board[3][2] == 3) && specificity[3][2] == 3))
		board[1][1] = 2;
	if ((board[1][1] == 4) && (board[2][2] == 4 && (board[0][2] == 3) && specificity[1][1] == 3))
		board[2][1] = 2;
	if ((board[1][1] == 4) && (board[2][2] == 4 && (board[1][3] == 3) && specificity[0][2] == 3))
		board[1][2] = 2;

	if ((board[1][2] == 4) && (board[2][1] == 4 && (board[0][1] == 3) && specificity[0][1] == 3))
		board[1][1] = 2;
	if ((board[1][2] == 4) && (board[2][1] == 4 && (board[2][3] == 3) && specificity[1][2] == 3))
		board[1][1] = 2;
	if ((board[1][1] == 4) && (board[2][2] == 4 && (board[3][1] == 3) && specificity[2][2] == 3))
		board[2][1] = 2;
	if ((board[1][1] == 4) && (board[2][2] == 4 && (board[0][2] == 3) && specificity[3][1] == 3))
		board[1][2] = 2;
}