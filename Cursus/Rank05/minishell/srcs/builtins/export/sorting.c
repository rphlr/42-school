/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:37:21 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 17:37:31 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*clone_env_list(t_env *head)
{
	t_env	*new_head;
	t_env	*new_current;
	t_env	*current;

	new_head = NULL;
	new_current = NULL;
	current = head;
	while (current)
	{
		add_env_node(&new_head, &new_current, clone_env_node(current));
		current = current->next;
	}
	return (new_head);
}

static void	swap_env_values(t_env *env1, t_env *env2)
{
	char	*tmp_name;
	char	*tmp_value;

	tmp_name = env1->name;
	tmp_value = env1->value;
	env1->name = env2->name;
	env1->value = env2->value;
	env2->name = tmp_name;
	env2->value = tmp_value;
}

static void	sort_env_list(t_env *env_cpy)
{
	t_env	*current;
	t_env	*tmp;

	current = env_cpy;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (ft_strcmp(current->name, tmp->name) > 0)
				swap_env_values(current, tmp);
			tmp = tmp->next;
		}
		current = current->next;
	}
}

static void	print_env_list(t_env *env_cpy)
{
	t_env	*current;

	current = env_cpy;
	while (current)
	{
		ft_printf("declare -x %s=\"%s\"\n", current->name, current->value);
		current = current->next;
	}
}

void	sorting_env(t_env *env_cpy)
{
	sort_env_list(env_cpy);
	print_env_list(env_cpy);
}
