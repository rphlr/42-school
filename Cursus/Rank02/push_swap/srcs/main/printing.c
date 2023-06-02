/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 07:36:20 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:54:02 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char *title)
{
	t_stack	*current;

	ft_printf(YELLOW" ---------------\n");
	ft_printf("|    %s:\t|\n", title);
	ft_printf("|---------------|\n");
	ft_printf("|     STACK\t|\n");
	ft_printf("|---------------|\n");
	current = stack;
	while (current)
	{
		ft_printf("| %i\t\t|\n", current->value);
		current = current->next;
	}
	ft_printf(" ---------------\n"RESET);
}

// void	print_stacks(t_stack *a, t_stack *b, char *title)
// {
// 	t_stack	*current_a;
// 	t_stack	*current_b;

// 	current_a = a;
// 	current_a = b;
// 	ft_printf(GREEN" -------------------------------\n");
// 	ft_printf("|\t   %s:\t\t|\n", title);
// 	ft_printf("|-------------------------------|\n");
// 	ft_printf("|  STACK A\t|  STACK B\t|\n");
// 	ft_printf("|-------------------------------|\n");
// 	while (current_a || current_b)
// 	{
// 		if (current_a)
// 		{
// 			ft_printf("| %i\t\t|", current_a->value);
// 			current_a = current_a->next;
// 		}
// 		else
// 			ft_printf("          |");
// 		if (current_b)
// 		{
// 			ft_printf(" %i\t\t|\n", current_b->value);
// 			current_b = current_b->next;
// 		}
// 		else
// 			ft_printf("\t\t|\n");
// 	}
// 	ft_printf(" -------------------------------\n"RESET);
// }
