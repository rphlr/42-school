/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:36:44 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 17:42:14 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	extract_name_value(char *token, char **name, char **value)
{
	*name = ft_strtok(token, "=");
	*value = ft_strtok(NULL, "=");
	if (!*name || !*value)
	{
		*name = token;
		*value = "";
	}
	else if (ft_strchr(*name, '='))
	{
		*name = NULL;
		*value = NULL;
	}
}

t_env	*new_env_item(char *name, char *value)
{
	t_env	*new_item;

	new_item = (t_env *)ft_gc_malloc(sizeof(t_env));
	if (!new_item)
		return (NULL);
	new_item->name = ft_strdup(name);
	new_item->value = ft_strdup(value);
	new_item->next = NULL;
	return (new_item);
}

t_env	*clone_env_node(t_env *src)
{
	t_env	*clone;

	clone = ft_gc_malloc(sizeof(t_env));
	if (!clone)
		return (NULL);
	clone->name = ft_strdup(src->name);
	clone->value = ft_strdup(src->value);
	clone->next = NULL;
	return (clone);
}

void	add_env_node(t_env **new_head, t_env **new_current, t_env *node)
{
	if (!*new_head)
	{
		*new_head = node;
		*new_current = node;
	}
	else
	{
		(*new_current)->next = node;
		*new_current = node;
	}
}
