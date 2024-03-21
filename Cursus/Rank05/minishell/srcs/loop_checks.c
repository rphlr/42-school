/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:54:06 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 19:54:24 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
	return (line);
}

void	add_to_history_list(t_history **head, char *line)
{
	t_history	*new_entry;
	t_history	*current;

	new_entry = ft_gc_malloc(sizeof(t_history));
	if (!new_entry)
		return ;
	new_entry->line = ft_strdup(line);
	new_entry->next = NULL;
	if (!(*head))
		*head = new_entry;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_entry;
	}
}

int	line_is_wspaces(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line++))
			return (0);
	}
	return (1);
}
