/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mslvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:09:17 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 20:10:46 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*init_new_node(void)
{
	t_env	*new_node;

	new_node = ft_gc_malloc(sizeof(t_env));
	if (new_node)
	{
		new_node->name = ft_strdup("MSLVL");
		new_node->value = ft_strdup("1");
		new_node->next = NULL;
	}
	return (new_node);
}

static void	update_mslvl_value(t_env *current)
{
	int		mslvl;
	char	*new_mslvl;

	mslvl = ft_atoi(current->value);
	new_mslvl = ft_itoa(mslvl + 1);
	current->value = new_mslvl;
}

t_env	*find_or_create_mslvl(t_env *head)
{
	t_env	*current;
	t_env	*last;
	int		found;

	current = head;
	last = NULL;
	found = 0;
	while (current)
	{
		if (ft_strcmp(current->name, "MSLVL") == 0)
		{
			update_mslvl_value(current);
			found = 1;
			break ;
		}
		last = current;
		current = current->next;
	}
	if (!found && last)
		last->next = init_new_node();
	else if (!found)
		head = init_new_node();
	return (head);
}
