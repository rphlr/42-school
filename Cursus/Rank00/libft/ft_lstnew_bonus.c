/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:26:39 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/24 17:26:39 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Creates a new linked list node and initializes it with the given
 * 			content.
 * @param	conten	Pointer to the content to be stored in the new node.
 * @return	Pointer to the newly created node, or NULL if an error occurred.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
