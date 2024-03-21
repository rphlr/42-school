/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariavillarroel <mariavillarroel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:54:46 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/30 18:09:59 by mariavillar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_cmd(t_global *global)
{
	int	primaries;

	primaries = 0;
	global->exit_code = 0;
	manage_exit(&global->exit_code);
	if (checking_primaries(global, primaries))
		return ;
	global->exit_code = execute_cmd(global->line->cmds->cmd,
			global->line->cmds->redir, global);
	manage_exit(&global->exit_code);
}

int	execute_cmd(char *cmd, t_redirection *redir, t_global *global)
{
	char	*argv[100];
	char	**paths;

	fill_argv(cmd, argv, global);
	if (!global->env)
	{
		ft_printf("minishell: %s: No such file or directory\n", argv[0]);
		global->exit_code = 127;
		return (global->exit_code);
	}
	paths = env_to_char(global);
	return (pid_creation(global, paths, argv, redir));
}

void	fill_argv(char *cmd, char **argv, t_global *global)
{
	int		i;
	int		j;
	char	*cmd_ptr;

	i = 0;
	cmd_ptr = cmd;
	j = -1;
	while (global->line->token[++j])
	{
		if (ft_strncmp(cmd_ptr, global->line->token[j],
				ft_strlen(global->line->token[j])) == 0)
		{
			argv[i] = global->line->token[j];
			i++;
			cmd_ptr += ft_strlen(global->line->token[j]);
			if (*cmd_ptr == ' ')
				cmd_ptr++;
		}
	}
	argv[i] = NULL;
}
