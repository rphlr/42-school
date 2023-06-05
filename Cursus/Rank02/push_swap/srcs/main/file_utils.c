/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:52:08 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_value_at_index(t_stack *stack, int index)
{
	t_stack	*current;
	int		current_idx;

	current = stack;
	current_idx = 0;
	while (current)
	{
		if (current_idx == index)
			return (current->value);
		current = current->next;
		current_idx++;
	}
	return (INT_MIN);
}

void	update_value_at_index(t_stack *stack, int index, int new_value)
{
	t_stack	*current;
	int		current_idx;

	current = stack;
	current_idx = 0;
	while (current)
	{
		if (current_idx == index)
		{
			current->value = new_value;
			break ;
		}
		current = current->next;
		current_idx++;
	}
}

void	swap_values(t_stack *stack, int i, int j)
{
	int	temp_i;
	int	temp_j;

	temp_i = find_value_at_index(stack, i);
	temp_j = find_value_at_index(stack, j);
	if (temp_i == INT_MIN || temp_j == INT_MIN)
		return ;
	update_value_at_index(stack, i, temp_j);
	update_value_at_index(stack, j, temp_i);
}

int	stack_get_value(t_stack *stack, int index)
{
	int		current_idx;
	t_stack	*current;

	current_idx = 0;
	current = stack;
	while (current)
	{
		if (current_idx == index)
			return (current->value);
		current = current->next;
		current_idx++;
	}
	return (INT_MIN);
}

int	get_index(t_stack **stack, int num)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = *stack;
	if (!current)
		return (-1);
	while (current->value != num)
	{
		index++;
		current = current->next;
	}
	return (index);
}
