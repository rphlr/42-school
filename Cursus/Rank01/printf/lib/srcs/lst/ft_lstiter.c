/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:26:23 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/24 17:26:23 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
