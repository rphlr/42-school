/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:24:28 by asenaud           #+#    #+#             */
/*   Updated: 2022/09/11 23:24:31 by asenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	case_a1(int **board, int **specificity);
void	case_a2(int **board, int **specificity);
void	case_a3(int **board, int **specificity);
void	case_b1(int **board, int **specificity);
void	case_b2(int **board, int **specificity);
void	case_b3(int **board, int **specificity);

void	ft_special_case(int **board, int **specificity)
{
	case_a1(board, specificity);
	case_a2(board, specificity);
	case_a3(board, specificity);
	case_b1(board, specificity);
	case_b2(board, specificity);
	case_b3(board, specificity);
}
