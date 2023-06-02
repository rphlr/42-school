/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:41:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:59:25 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		iter = *a;
		while (iter->next)
			iter = iter->next;
		iter->next = tmp;
		ft_printf("ra\n");
	}
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		iter = *b;
		while (iter->next)
			iter = iter->next;
		iter->next = tmp;
		ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
