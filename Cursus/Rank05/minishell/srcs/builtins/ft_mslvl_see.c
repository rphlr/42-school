/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mslvl_see.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:53:00 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 18:58:33 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mslvl_see(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (!ft_strcmp(current->name, "MSLVL"))
		{
			if (!ft_strcmp(current->value, "1"))
				ft_printf(SHLVL, current->value, "");
			else
				ft_printf(SHLVL, current->value, "s");
			return ;
		}
		current = current->next;
	}
}
