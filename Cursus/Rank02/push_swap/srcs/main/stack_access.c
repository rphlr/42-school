/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:55:47 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = ft_gc_malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}

bool	stack_contains(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*parse_and_create_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		value;

	stack = NULL;
	i = 0;
	while (++i < argc)
	{
		if (is_number(argv[i]) && is_int(argv[i]))
		{
			value = ft_atoi(argv[i]);
			if (!stack_contains(stack, value))
				stack_push(&stack, value);
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	return (stack);
}
