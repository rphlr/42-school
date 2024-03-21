/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_variable_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:47:07 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 10:47:27 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_variable_name(char *ptoken)
{
	char	*start;
	int		len;
	char	*var_name;

	start = ptoken;
	while (*ptoken && ((*ptoken >= 'a' && *ptoken <= 'z') || (*ptoken >= 'A'
				&& *ptoken <= 'Z') || (*ptoken >= '0' && *ptoken <= '9')
			|| *ptoken == '_'))
		ptoken++;
	len = ptoken - start;
	var_name = (char *)ft_gc_malloc(len + 1);
	if (!var_name)
		return (NULL);
	ft_strncpy(var_name, start, len);
	var_name[len] = '\0';
	return (var_name);
}

int	biggest_var_value(t_env	*env)
{
	int		len;
	int		len_biggest;
	t_env	*current;

	len_biggest = 0;
	current = env;
	while (current)
	{
		len = ft_strlen(current->value);
		if (len > len_biggest)
			len_biggest = len;
		current = current->next;
	}
	return (len_biggest);
}
