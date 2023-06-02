/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:25:59 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/26 10:50:49 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function adds a value at the begining of a list.
* @param	t_list	The list.
* @param	t_list	The value.
* @return	void	No return value needed.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		;
	new->next = *lst;
	*lst = new;
}
