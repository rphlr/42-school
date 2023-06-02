/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:59:47 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*iter;
	t_stack	*prev;

	if (*a && (*a)->next)
	{
		iter = *a;
		prev = NULL;
		while (iter->next)
		{
			prev = iter;
			iter = iter->next;
		}
		iter->next = *a;
		prev->next = NULL;
		*a = iter;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **b)
{
	t_stack	*iter;
	t_stack	*prev;

	if (*b && (*b)->next)
	{
		iter = *b;
		prev = NULL;
		while (iter->next)
		{
			prev = iter;
			iter = iter->next;
		}
		iter->next = *b;
		prev->next = NULL;
		*b = iter;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
