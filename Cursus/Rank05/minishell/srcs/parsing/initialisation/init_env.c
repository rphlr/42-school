/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:18:59 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 14:53:21 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*new_env_items(char *env_str)
{
	t_env	*new_item;

	new_item = ft_gc_malloc(sizeof(t_env));
	if (!new_item)
		return (NULL);
	if (ft_strchr(env_str, '='))
	{
		new_item->name = ft_strndup(env_str, ft_strchr(env_str, '=') - env_str);
		new_item->value = ft_strdup(ft_strchr(env_str, '=') + 1);
	}
	new_item->next = NULL;
	return (new_item);
}

static void	add_to_list(t_env **head, t_env **current, t_env *new_item)
{
	if (!*head)
	{
		*head = new_item;
		*current = *head;
	}
	else
	{
		(*current)->next = new_item;
		*current = new_item;
	}
}

// static t_env	*increment_mslvl(t_env *head)
// {
// 	t_env	*current;
// 	t_env	*last;
// 	char	*new_mslvl;
// 	int		mslvl;
// 	int		found;
// 	t_env	*new_node;

// 	current = head;
// 	last = NULL;
// 	found = 0;
// 	while (current)
// 	{
// 		if (ft_strcmp(current->name, "MSLVL") == 0)
// 		{
// 			mslvl = ft_atoi(current->value);
// 			new_mslvl = ft_itoa(mslvl + 1);
// 			current->value = new_mslvl;
// 			found = 1;
// 			break ;
// 		}
// 		last = current;
// 		current = current->next;
// 	}
// 	if (!found)
// 	{
// 		new_node = ft_gc_malloc(sizeof(t_env));
// 		if (new_node)
// 		{
// 			new_node->name = ft_strdup("MSLVL");
// 			new_node->value = ft_strdup("1");
// 			new_node->next = NULL;
// 			if (last)
// 				last->next = new_node;
// 			else
// 				head = new_node;
// 		}
// 	}
// 	return (head);
// }

static t_env	*remove_otherlvls(t_env *head)
{
	t_env	*current;
	t_env	*last;

	current = head;
	last = NULL;
	while (current)
	{
		if (!ft_strcmp(current->name, "SHLVL") || !ft_strcmp(current->name,
				"MAKELEVEL"))
		{
			if (last)
				last->next = current->next;
			else
				head = current->next;
			current = current->next;
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
	return (head);
}

t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	*current;
	t_env	*new_item;

	head = NULL;
	current = NULL;
	while (*envp)
	{
		new_item = new_env_items(*envp);
		if (!new_item)
			return (NULL);
		add_to_list(&head, &current, new_item);
		envp++;
	}
	head = find_or_create_mslvl(head);
	head = remove_otherlvls(head);
	return (head);
}
