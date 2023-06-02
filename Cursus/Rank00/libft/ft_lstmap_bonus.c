/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:25:24 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/24 17:25:24 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Creates a new linked list node and initializes it with the given
 * 			content, freeing the content if an error occurs.
 * @param	content	Pointer to the content to be stored in the new node.
 * @return	Pointer to the newly created node, or NULL if an error occurred.
 */
t_list	*ft_lstnew_for_strict_francinette(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free(content);
		free(new);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

/**
 * @brief	Iterates over a linked list and applies a function to each element,
 * 			creating a new linked list with the resulting elements.
 * @param	lst	Pointer to the head of the input linked list.
 * @param	f	Pointer to a function that takes in a pointer to an element and
 * 				returns a pointer to the transformed element.
 * @param	del	Pointer to a function that takes in a pointer to an element
 * 				and frees it.
 * @return	Pointer to the head of the new linked list, or NULL if an error
 * 			occurred.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew_for_strict_francinette(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
