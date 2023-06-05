/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:50:53 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	else if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	else if (size == 3)
		sort_three_elements(a);
	else if (size <= 10)
	{
		while (size > 3)
		{
			approximity(a, find_min(*a));
			pb(a, b);
			size--;
		}
		sort_three_elements(a);
		while (*b)
			pa(a, b);
	}
}

void	sort_large(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*sorted_a;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	sorted_a = sort_stack(*a);
	sort_chunks(a, b, sorted_a, size);
	sort_remaining(a, b);
}

void	sort_three_elements(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_chunks(t_stack **a, t_stack **b, t_stack *sorted_a, int size)
{
	int		divider;
	int		cur_divider;
	int		size_stack_b;
	int		idx_key_nbr;
	int		key_nbr;

	divider = (size + 367) / 67;
	size_stack_b = 0;
	cur_divider = 1;
	while (size_stack_b < ((size / divider) * (divider - 1)))
	{
		idx_key_nbr = (size / divider) * cur_divider;
		key_nbr = find_key_nbr(sorted_a, idx_key_nbr);
		if ((*a)->value <= key_nbr)
		{
			pb(a, b);
			size_stack_b++;
		}
		else
			ra(a);
		if (size_stack_b == idx_key_nbr)
			cur_divider++;
	}
}

void	sort_remaining(t_stack **a, t_stack **b)
{
	int		size;
	int		key_nbr;

	size = stack_size(*a);
	while (stack_size(*a) > 3)
	{
		approximity(a, find_min(*a));
		pb(a, b);
	}
	sort_three_elements(a);
	while (*b)
	{
		key_nbr = find_max(*b);
		if ((*b)->value != key_nbr)
			approximity_b(b, key_nbr);
		else
			pa(a, b);
	}
}
