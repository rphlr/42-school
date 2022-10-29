/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_missing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:36:09 by rrouille          #+#    #+#             */
/*   Updated: 2022/09/11 13:36:13 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_search_missing(int **numbers, int n_ieme)
{
	int	i;
	int	nb_find;

	i = 0;
	nb_find = 0;
	while (i < 4)
	{
		if (numbers[0][i] != -1)
		{
			nb_find++;
			if (nb_find == n_ieme)
				return (numbers[0][i]);
		}
		i++;
	}
	return (0);
}

int	ft_missing_colomn(int **board, int map_size, int **numbers, int i)
{
	int	colonne;
	int	nb_zero;

	colonne = 0;
	nb_zero = 0;
	while (colonne < map_size)
	{
		if (board[colonne][i] == 0)
		{
			numbers[1][nb_zero] = colonne;
			nb_zero++;
		}
		else
			numbers[0][board[colonne][i] - 1] = -1;
		colonne++;
	}
	return (nb_zero);
}

int	ft_missing_line(int **board, int map_size, int **numbers, int i)
{
	int	line;
	int	nb_zero;

	line = 0;
	nb_zero = 0;
	while (line < map_size)
	{
		if (board[i][line] == 0)
		{
			numbers[1][nb_zero] = line;
			nb_zero++;
		}
		else
			numbers[0][board[i][line] - 1] = -1;
		line++;
	}
	return (nb_zero);
}
