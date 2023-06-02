/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 07:36:20 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/18 17:08:47 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_copy(t_stack *stack)
{
	t_stack	*copy;

	copy = NULL;
	while (stack)
	{
		stack_push(&copy, stack->value);
		stack = stack->next;
	}
	return (copy);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (size <= 10)
		sort_small(&a, &b);
	else
		sort_large(&a, &b);
}

int	count_args(char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	return (count);
}
