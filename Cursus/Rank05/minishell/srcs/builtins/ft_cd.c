/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariavillarroel <mariavillarroel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:40:18 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 00:54:36 by mariavillar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *cmd, t_global *global)
{
	char	*path;
	char	**token;

	token = ft_split(cmd, ' ');
	if (token[1] == NULL)
	{
		path = get_env_value("HOME", global->env);
		if (path == NULL)
			ft_printf("minishell: cd: HOME not set\n");
		else if (chdir(path) == -1)
			ft_printf("minishell: cd: %s: %s\n", path, strerror(errno));
	}
	else if (token[2] != NULL)
		ft_printf("minishell: cd: too many arguments\n");
	else if (chdir(token[1]) == -1)
	{
		ft_printf("minishell: cd: %s: %s\n", token[1],
			strerror(errno));
	}
}
