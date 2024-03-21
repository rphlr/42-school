/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:41:30 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/18 23:44:46 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_env_item(t_env **head, char *name)
{
	t_env	*current;
	t_env	*prev;

	current = *head;
	prev = NULL;
	while (current && ft_strcmp(current->name, name) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (!prev)
		*head = current->next;
	else
		prev->next = current->next;
}

void	ft_unset(t_global *global, t_line *line)
{
	int		i;
	char	*name_to_remove;

	i = 1;
	if (line->count->nbr_tokens < 2)
	{
		ft_printf("minishell: unset: not enough arguments\n");
		return ;
	}
	else
	{
		while (line->token[i])
		{
			name_to_remove = line->token[i++];
			remove_env_item(&global->env, name_to_remove);
		}
	}
}
