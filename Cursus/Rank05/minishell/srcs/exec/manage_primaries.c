/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_primaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:21:32 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/31 14:58:30 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checking_primaries(t_global *global, int primaries)
{
	if (global->line->count->special_cases == true)
	{
		execute_specials(global);
		return (1);
	}
	primaries = cmd_is_primaries(global->line->cmds->cmd);
	if (primaries)
	{
		execute_primaries(global->line->cmds->cmd, global);
		return (1);
	}
	if (!get_env_value("PATH", global->env))
	{
		ft_printf("minishell: %s: No such file or directory\n",
			global->line->cmds->cmd);
		global->exit_code = 127;
		manage_exit(&global->exit_code);
		return (1);
	}
	return (0);
}

int	cmd_is_primaries(char *cmd)
{
	char	*cmd_copy;
	char	*first_word;

	cmd_copy = ft_strdup(cmd);
	first_word = ft_strtok(cmd_copy, " ");
	if (!ft_strcmp(first_word, "echo") || !ft_strcmp(first_word, "cd")
		|| !ft_strcmp(first_word, "pwd") || !ft_strcmp(first_word, "export")
		|| !ft_strcmp(first_word, "unset") || !ft_strcmp(first_word, "env")
		|| !ft_strcmp(first_word, "exit") || !ft_strcmp(first_word, "clear")
		|| !ft_strcmp(first_word, "easter_egg") || !ft_strcmp(first_word, "ee")
		|| !ft_strcmp(first_word, "ms"))
		return (1);
	return (0);
}

void	execute_primaries_2(t_global *global, char *first_word)
{
	if (!ft_strcmp(first_word, "unset"))
		ft_unset(global, global->line);
	else if (!ft_strcmp(first_word, "env"))
		ft_env(global);
	else if (!ft_strcmp(first_word, "exit"))
		ft_exit(global);
	else if (!ft_strcmp(first_word, "clear"))
		ft_printf(C_CLEAR);
	else if (!ft_strcmp(first_word, "easter_egg")
		|| !ft_strcmp(first_word, "ee"))
		ft_easter_egg();
	else if (!ft_strcmp(first_word, "ms"))
		ft_mslvl_see(global->env);
}

void	execute_primaries(char	*cmd, t_global *global)
{
	char	*cmd_copy;
	char	*first_word;

	cmd_copy = ft_strdup(cmd);
	first_word = ft_strtok(cmd_copy, " ");
	if (!ft_strcmp(first_word, "echo"))
		ft_echo(cmd, global);
	else if (!ft_strcmp(first_word, "cd"))
		ft_cd(cmd, global);
	else if (!ft_strcmp(first_word, "pwd"))
		ft_pwd(global->line);
	else if (!ft_strcmp(first_word, "export"))
		ft_export(global, global->line);
	else
		execute_primaries_2(global, first_word);
}
