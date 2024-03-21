/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:06:53 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/31 16:17:30 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char *command, char **paths)
{
	char	*path;
	char	*tmp;

	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, F_OK) == 0)
			return (command);
		return (NULL);
	}
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		path = ft_strjoin(tmp, command);
		if (access(path, F_OK) == 0)
			return (path);
		paths++;
	}
	return (NULL);
}

char	**env_to_char(t_global *global)
{
	char	**paths;

	if (!global->env)
		return (NULL);
	while (ft_strcmp(global->env->name, "PATH"))
	{
		global->env = global->env->next;
		if (!global->env)
			return (NULL);
	}
	paths = ft_gc_malloc(sizeof(char *) * (ft_strlen(global->env->value) + 1));
	if (!paths)
		return (NULL);
	paths = ft_split(global->env->value, ':');
	return (paths);
}

char	*found_command(t_global *global, char **paths, char *argv[])
{
	char	*path;

	path = get_path(argv[0], paths);
	if (ft_strcmp(argv[0], ">>") == 0 || ft_strcmp(argv[0], ">") == 0
		|| ft_strcmp(argv[0], "<") == 0 || ft_strcmp(argv[0], "<<") == 0)
	{
		global->exit_code = 0;
		manage_exit(&global->exit_code);
		return (path);
	}
	if (!path)
	{
		ft_printf("minishell: %s: command not found\n", argv[0]);
		global->exit_code = 127;
		manage_exit(&global->exit_code);
	}
	return (path);
}

int	count_cmds(t_cmds *cmds)
{
	int		num_cmds;
	t_cmds	*tmp;

	num_cmds = 0;
	tmp = cmds;
	while (tmp)
	{
		num_cmds++;
		tmp = tmp->next;
	}
	return (num_cmds);
}
