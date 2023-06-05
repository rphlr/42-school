/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:36 by rrouille          #+#    #+#             */
/*   Updated: 2022/12/17 15:11:09 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief	Reads data from the file descriptor into a buffer and appends the
 * 			data to a list of strings
 * @return	Nothing needs to be returned.
 * @param	int		fd : The file descriptor to read from
 * @param	t_list	**stash : A pointer to a pointer to a linked list. The
 * 					function will append the data read from the file to the
 * 					linked list.
 */
void	prepare_stash_from_file(int fd, t_list **stash)
{
	char	*buffer;
	int		num_bytes;

	num_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!found_new_line(*stash) && num_bytes != 0)
	{
		if (buffer == NULL)
			return ;
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((*stash == NULL && num_bytes == 0) || num_bytes == -1)
		{
			free(buffer);
			if (num_bytes == -1)
				free_stash(*stash);
			*stash = NULL;
			return ;
		}
		buffer[num_bytes] = '\0';
		append_buffer_to_stash(stash, buffer, num_bytes);
	}
	free(buffer);
}

/**
 * @brief	Appends the given buffer to the end of the linked list pointed to
 * 			by stash.
 * @return	Nothing needs to be returned.
 * @param	t_list	**stash : Pointer to a pointer to the head of the linked
 * 					list to append to.
 * @param	char	*buffer : Pointer to the array of characters to append to
 * 					the linked list.
 * @param	int		num_bytes : The number of bytes in the buffer to append to
 * 					the linked list.
 */
void	append_buffer_to_stash(t_list **stash, char *buffer, int num_bytes)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->content = malloc(sizeof(char) * (num_bytes + 1));
	if (new_node == NULL
		|| new_node->content == NULL)
		return ;
	new_node->next = NULL;
	i = 0;
	while (buffer[i] && i < num_bytes)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
		*stash = new_node;
	else
	{
		last = ft_lstlast(*stash);
		last->next = new_node;
	}
}

/**
 * @brief	Reads a line from a linked list of strings and stores it in a
 * 			string.
 * @return	Nothing needs to be returned.
 * @param	t_list	*stash : A pointer to the linked list of strings to read
 * 					from.
 * @param	char	**line : A pointer to a pointer to a string. The function
 * 					will store the line read from the stash in this string.
 */
void	read_line_from_stash(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/**
 * @brief	Removes the last element of a linked list.
 * @return	A pointer to the removed element of the linked list
 * @param	t_list	**list : A pointer to a pointer to a linked list. The
 * 					function will remove the last element from this linked
 * 					list.
 */
t_list	*trim_last_list_element(t_list **lst)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;

	clean_node = malloc(sizeof(t_list));
	if (lst == NULL || clean_node == NULL)
	{
		*lst = clean_node;
		return (NULL);
	}
	clean_node->next = NULL;
	last = ft_lstlast(*lst);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	clean_node->content = trim_last_list_element_helper(last, i);
	if (clean_node->content == NULL)
		return (NULL);
	free_stash(*lst);
	*lst = clean_node;
	return (clean_node);
}

/**
 * @brief	Reads a line from a file descriptor and returns it as a string.
 * @return	A pointer to the string containing the line read from the file.
 * @param	int		fd : The file descriptor to read from.
 */
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	prepare_stash_from_file(fd, &stash);
	if (stash == NULL)
		return (NULL);
	read_line_from_stash(stash, &line);
	trim_last_list_element(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
