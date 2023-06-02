/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:41:53 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = temp;
		ft_printf("sa\n");
	}
}

void	sb(t_stack **b)
{
	int	temp;

	if (*b && (*b)->next)
	{
		temp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = temp;
		ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
		ft_printf("pb\n");
	}
}
