/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:29:55 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 22:45:55 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_case_min_max(int **board, int **specificity, int map_size);
void	ft_no_hidden_box(int **board, int **specificity, int map_size);
void	ft_three_complet(int **board, int **specificity, int map_size);
void	ft_decide_columns(int **board);
void	ft_decide_lines(int **board);
void	ft_special_case(int **board, int **specificity);
void	ft_place_one(int **board, int **specificity);
void	ft_special_three(int **board, int **specificity);
void	ft_special_one(int **board, int **specificity);
void	ft_magic_for(int **board, int **specificity);
void	ft_magic_two(int **board, int **specificity);
void	ft_complett_column(int **board, int **specificity, int map_size);
void	ft_complett_line(int **board, int **specificity, int map_size);
void	ft_last(int **board, int search);

int	ft_count(int **board, int search)
{
	int	nb_search;
	int	i;
	int	j;

	nb_search = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (board[i][j] == search)
			{
				nb_search ++;
			}
			j++;
		}
		i++;
	}
	return (nb_search);
}

void	initial_check(int **board, int **specificity, int map_size)
{
	ft_case_min_max(board, specificity, map_size);
	ft_no_hidden_box(board, specificity, map_size);
	if (ft_count(board, 4) == 3)
		ft_last(board, 4);
	ft_place_one(board, specificity);
	ft_special_three(board, specificity);
	ft_special_one(board, specificity);
	ft_magic_for(board, specificity);
	ft_magic_two(board, specificity);
	ft_three_complet(board, specificity, map_size);
}

void	iterate_check(int **board, int **specificity, int map_size)
{
	int	i;

	i = 4;
	ft_three_complet(board, specificity, map_size);
	ft_special_case(board, specificity);
	ft_complett_line(board, specificity, map_size);
	ft_complett_column(board, specificity, map_size);
	while (i > 0)
	{
		if (ft_count(board, i) == 3)
		{
			ft_last(board, i);
		}
		i--;
	}
	if (ft_count(board, 0) == 4)
	{
		ft_decide_columns(board);
		ft_decide_lines(board);
	}
}

void	ft_solve(int **board, int **specificity, int map_size)
{
	int	i;
	int	a;
	int	j;

	initial_check(board, specificity, map_size);
	j = 0;
	while (j < 3)
	{
		iterate_check(board, specificity, map_size);
		j++;
	}
}
