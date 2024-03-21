/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_specials.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:12:13 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/31 14:54:12 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redir(t_global *global, t_cmds *curr_cmd)
{
	execute_cmd(curr_cmd->cmd, curr_cmd->redir, global);
}

void	ft_or(t_global *global, t_cmds *curr_cmd, t_cmds *next_cmd)
{
	if (execute_cmd(curr_cmd->cmd, curr_cmd->redir, global) != 0)
		execute_cmd(next_cmd->cmd, next_cmd->redir, global);
}

void	ft_and(t_global *global, t_cmds *curr_cmd, t_cmds *next_cmd)
{
	if (execute_cmd(curr_cmd->cmd, curr_cmd->redir, global) == 0)
		execute_cmd(next_cmd->cmd, next_cmd->redir, global);
}

void	ft_semicolon(t_global *global, t_cmds *curr_cmd, t_cmds *next_cmd)
{
	execute_cmd(curr_cmd->cmd, curr_cmd->redir, global);
	execute_cmd(next_cmd->cmd, next_cmd->redir, global);
}

void	execute_specials(t_global *global)
{
	t_count	*count_tmp;
	t_cmds	*curr_cmd;
	t_token	*type_tmp;

	count_tmp = global->line->count;
	curr_cmd = global->line->cmds;
	type_tmp = global->line->type;
	while (count_tmp->special_cases)
	{
		while (!(*type_tmp == INPUT || *type_tmp == OUTPUT || *type_tmp
				== APPEND || *type_tmp == HEREDOC || *type_tmp == AND
				|| *type_tmp == OR || *type_tmp == SEMICOLON || *type_tmp
				== PIPE) && *type_tmp != END)
			type_tmp++;
		call_checks(count_tmp, global, curr_cmd, type_tmp);
		if (curr_cmd->next)
			curr_cmd = curr_cmd->next;
		type_tmp++;
		if (!count_tmp->nbr_inputs && !count_tmp->nbr_outputs
			&& !count_tmp->nbr_appends && !count_tmp->nbr_heredocs
			&& !count_tmp->nbr_ors && !count_tmp->nbr_ands
			&& !count_tmp->nbr_semicolons && !count_tmp->nbr_pipes)
			count_tmp->special_cases = false;
	}
}
