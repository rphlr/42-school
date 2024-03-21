/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariavillarroel <mariavillarroel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:55:07 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/30 15:07:54 by mariavillar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_or(t_count *count_tmp, t_global *global, t_cmds *curr_cmd,
	t_token *type_tmp)
{
	if (count_tmp->nbr_ors > 0 && *type_tmp == OR)
	{
		count_tmp->nbr_ors--;
		ft_or(global, curr_cmd, curr_cmd->next);
		if (global->exit_code == 0)
			return (1);
		if (curr_cmd->next)
		{
			curr_cmd = curr_cmd->next;
			type_tmp++;
			while (*type_tmp != OR && *type_tmp != END)
				type_tmp++;
			if (*type_tmp == END)
				return (1);
		}
		return (1);
	}
	return (0);
}

int	check_and(t_count *count_tmp, t_global *global, t_cmds *curr_cmd,
	t_token *type_tmp)
{
	if (count_tmp->nbr_ands > 0 && *type_tmp == AND)
	{
		count_tmp->nbr_ands--;
		ft_and(global, curr_cmd, curr_cmd->next);
		if (curr_cmd->next)
		{
			curr_cmd = curr_cmd->next;
			type_tmp++;
			while (*type_tmp != AND && *type_tmp != END)
				type_tmp++;
			if (*type_tmp == END)
				return (1);
		}
		return (1);
	}
	return (0);
}

int	check_semicolon_and_pipe(t_count *count_tmp, t_global *global,
	t_cmds *curr_cmd, t_token *type_tmp)
{
	if (count_tmp->nbr_semicolons > 0 && *type_tmp == SEMICOLON)
	{
		count_tmp->nbr_semicolons--;
		ft_semicolon(global, curr_cmd, curr_cmd->next);
		return (1);
	}
	else if (count_tmp->nbr_pipes > 0 && *type_tmp == PIPE)
	{
		if (count_tmp->nbr_pipes > 1)
			execute_pipeline(global, curr_cmd);
		else
			ft_pipe(global, curr_cmd, curr_cmd->next);
		count_tmp->nbr_pipes = 0;
		return (1);
	}
	return (0);
}

int	check_special(t_count *count_tmp, t_global *global, t_cmds *curr_cmd,
	t_token *type_tmp)
{
	if (*type_tmp == INPUT || *type_tmp == HEREDOC || *type_tmp == APPEND
		|| *type_tmp == OUTPUT)
	{
		if (count_tmp->nbr_inputs > 0 && *type_tmp == INPUT)
			count_tmp->nbr_inputs--;
		else if (count_tmp->nbr_heredocs > 0 && *type_tmp == HEREDOC)
			count_tmp->nbr_heredocs--;
		else if (count_tmp->nbr_appends > 0 && *type_tmp == APPEND)
			count_tmp->nbr_appends--;
		else if (count_tmp->nbr_outputs > 0 && *type_tmp == OUTPUT)
			count_tmp->nbr_outputs--;
		ft_redir(global, curr_cmd);
		return (1);
	}
	return (0);
}

void	call_checks(t_count *count_tmp, t_global *global, t_cmds *curr_cmd,
	t_token *type_tmp)
{
	if (check_special(count_tmp, global, curr_cmd, type_tmp))
		return ;
	else if (check_or(count_tmp, global, curr_cmd, type_tmp))
		return ;
	else if (check_and(count_tmp, global, curr_cmd, type_tmp))
		return ;
	else if (check_semicolon_and_pipe(count_tmp, global, curr_cmd, type_tmp))
		return ;
}
