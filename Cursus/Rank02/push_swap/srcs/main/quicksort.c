/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:50:05 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	while (stack)
	{
		stack_push(&temp, stack->value);
		stack = stack->next;
	}
	quicksort(temp, 0, stack_size(temp) - 1);
	return (temp);
}

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(t_stack *stack, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = stack_get_value(stack, high);
	i = low - 1;
	j = i;
	while (++j < high)
	{
		if (stack_get_value(stack, j) <= pivot)
		{
			i++;
			swap_values(stack, i, j);
		}
	}
	swap_values(stack, i + 1, high);
	return (i + 1);
}

void	quicksort(t_stack *stack, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(stack, low, high);
		quicksort(stack, low, pi - 1);
		quicksort(stack, pi + 1, high);
	}
}
