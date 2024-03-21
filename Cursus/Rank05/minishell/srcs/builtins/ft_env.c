/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:42:00 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 16:52:52 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_list_to_array(t_env *env_list)
{
	int		count;
	t_env	*tmp;
	int		i;
	char	**env_array;

	tmp = env_list;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	env_array = ft_gc_malloc((count + 1) * sizeof(char *));
	if (!env_array)
		return (NULL);
	tmp = env_list;
	i = -1;
	while (++i < count)
	{
		env_array[i] = ft_strjoin(tmp->name, "=");
		env_array[i] = ft_strjoin(env_array[i], tmp->value);
		tmp = tmp->next;
	}
	env_array[count] = NULL;
	return (env_array);
}

char	*get_env_value(char *name, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_env(t_global *global)
{
	t_env	*tmp;

	tmp = global->env;
	while (tmp)
	{
		ft_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
