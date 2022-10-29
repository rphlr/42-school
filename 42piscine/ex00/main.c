/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:55:15 by rrouille          #+#    #+#             */
/*   Updated: 2022/09/10 20:24:14 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_solve(int **board, int **specificity, int map_size);
void	ft_init_tab(int **specificity, int **board, int **box, int map_size);
int		ft_initial_control(int argc, char **argv, int map_size,
			int **specificity);
int		ft_sum_control(int map_size, int **specificity);
void	ft_end_prog(int **specificity, int **board, int **box, int map_size);
int		ft_check_solve(int **board);
void	ft_print_solve(int **board);

int	main(int argc, char **argv)
{
	int	map_size;
	int	**specificity;
	int	**board;
	int	**box;
	int	i;

	i = 0;
	map_size = 4;
	specificity = malloc(sizeof(int *) * 4);
	board = malloc(sizeof(int *) * map_size);
	box = malloc(sizeof(int *) * map_size * map_size);
	ft_init_tab(specificity, board, box, map_size);
	if (!ft_initial_control(argc, argv, map_size, specificity) \
			|| !ft_sum_control(map_size, specificity))
		write(1, "Error\n", 6);
	else
	{
		ft_solve(board, specificity, map_size);
		if (ft_check_solve(board))
			ft_print_solve(board);
		else
			write(1, "Error\n", 6);
	}
	ft_end_prog(specificity, board, box, map_size);
	return (0);
}
