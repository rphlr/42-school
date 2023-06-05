/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:53:14 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_key_nbr(t_stack *stack, int divider)
{
	int	i;

	i = 0;
	while (++i < divider)
		stack = stack->next;
	return (stack->value);
}

void	move_rb(t_stack **b, int *max_index)
{
	while (*max_index >= 0)
	{
		rb(b);
		(*max_index)--;
	}
	rb(b);
}

void	move_rrb(t_stack **b, int *max_index)
{
	while (*max_index > stack_size(*b))
	{
		rrb(b);
		(*max_index)++;
	}
	rrb(b);
}

void	approximity_b(t_stack **b, int num)
{
	int	max_index;
	int	proximity;

	max_index = get_index(b, num);
	if (max_index == -1)
		return ;
	proximity = (stack_size(*b) / 2);
	if (proximity > max_index)
		move_rb(b, &max_index);
	else
	{
		max_index = get_index(b, num);
		move_rrb(b, &max_index);
	}
}

void	approximity(t_stack **a, int num)
{
	int	index;
	int	proximity;

	index = get_index(a, num);
	if (index == -1)
		return ;
	proximity = (stack_size(*a) / 2);
	if (proximity > index)
	{
		while (index > 0)
		{
			ra(a);
			index--;
		}
	}
	else
	{
		while (index < stack_size(*a))
		{
			rra(a);
			index++;
		}
	}
}
