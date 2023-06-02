/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:25:43 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/24 17:25:43 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function delete something in a list.
* @param	t_list	The list.
* @param	ft		The function to delete just one thing in a list.
* @return	void	No return value needed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		;
	del(lst->content);
	free(lst);
}
