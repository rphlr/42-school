/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:53:18 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 17:37:16 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_invalid_token(char *token)
{
	if (!ft_isalpha(token[0]) && token[0] != '_')
	{
		ft_printf("minishell: export: `%s': not a valid identifier\n", token);
		return (1);
	}
	return (0);
}

static int	handle_invalid_name_value(char *name, char *value)
{
	if (!name || !value)
	{
		ft_printf("minishell: export: bad assignment\n");
		return (1);
	}
	return (0);
}

static void	update_or_add_env_item(t_global *global, char *name, char *value)
{
	t_env	*current;
	t_env	*new_item;

	current = global->env;
	while (current)
	{
		if (!ft_strcmp(current->name, name))
		{
			current->value = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
	new_item = new_env_item(name, value);
	if (!new_item)
		return ;
	if (!global->env)
		global->env = new_item;
	else
	{
		current = global->env;
		while (current->next)
			current = current->next;
		current->next = new_item;
	}
}

void	ft_export(t_global *global, t_line *line)
{
	char	*name;
	char	*value;
	int		i;

	if (line->count->nbr_tokens < 2)
	{
		sorting_env(clone_env_list(global->env));
		return ;
	}
	i = 1;
	while (line->token[i])
	{
		if (handle_invalid_token(line->token[i]))
			return ;
		extract_name_value(line->token[i], &name, &value);
		if (handle_invalid_name_value(name, value))
			return ;
		update_or_add_env_item(global, name, value);
		i++;
	}
}
