/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_or_cmd_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:24:11 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 15:47:50 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	line_does_not_exist(t_global *global, char *line)
{
	global->line = init_line(line, global);
	if (!global->line)
	{
		global->exit_code = 258;
		manage_exit(&global->exit_code);
		return (1);
	}
	return (0);
}

int	command_empty(t_global *global)
{
	if (line_is_wspaces(global->line->cmds->cmd))
	{
		printf("minishell: %s: command not found\n", global->line->cmds->cmd);
		global->exit_code = 127;
		manage_exit(&global->exit_code);
		return (1);
	}
	return (0);
}
