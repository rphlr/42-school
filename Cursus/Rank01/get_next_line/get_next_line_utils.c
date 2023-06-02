/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:52:32 by rrouille          #+#    #+#             */
/*   Updated: 2022/12/15 17:29:15 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief	Finds the last element in a linked list.
 * @return	A pointer to the last element in the linked list, or NULL if the
 * 			list is empty.
 * @param	t_list	*lst : A pointer to the first element in the linked list
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
 * @brief	Trims the content of the last element in a linked list.
 * @return	A pointer to a new string containing the trimmed content of the
 * 			last element in the list, or NULL if an error occurred.
 * @param	t_list	*last : A pointer to the last element in the linked list.
 * @param	int		i : The index at which to start trimming the last
 * 					element's content.
 */
char	*trim_last_list_element_helper(t_list *last, int i)
{
	int		j;
	int		len;
	char	*trimmed_content;

	len = 0;
	while (last->content[len])
		len++;
	trimmed_content = malloc(sizeof(char) * (len - i + 1));
	if (trimmed_content == NULL)
		return (NULL);
	j = 0;
	while (last->content[i])
		trimmed_content[j++] = last->content[i++];
	trimmed_content[j] = '\0';
	return (trimmed_content);
}

/**
 * @brief	Determines if a newline character exists in the last element of a
 * 			linked list.
 * @return	A boolean indicating whether or not a newline character was found
 * 			in the last element of the list.
 * @param	t_list	*stash : A pointer to the first element in the linked list.
 */
bool	found_new_line(t_list *stash)
{
	int		i;

	if (stash == NULL)
		return (false);
	i = 0;
	if (stash == NULL)
		return (false);
	while (stash->next != NULL)
		stash = stash->next;
	while (stash->content[i])
	{
		if (stash->content[i] == '\n')
			return (true);
	i++;
	}
	return (false);
}

/**
 * @brief	Generates a string from the content of a linked list.
 * @return	Nothing needs to be returned.
 * @param	char	**line : A double pointer to a character that will be used
 * 					to store the generated string.
 * @param	t_list	*stash : A pointer to the first element in the linked list.
 */
void	generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/**
 * @brief	Frees all memory occupied by the given linked list and its
 * 			elements.
 * @return	Nothing needs to be returned.
 * @param	t_list	*stash : Pointer to the head of the linked list to free.
 */
void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
