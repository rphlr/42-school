/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrlc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:01:34 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 20:02:55 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc_state(void)
{
	int		exit_code;

	exit_code = 1;
	manage_exit(&exit_code);
}

static void	handle_blocking_cmd_state(pid_t child_pid)
{
	int		exit_code;

	ft_printf("\n");
	if (child_pid > 0)
		kill(child_pid, SIGINT);
	exit_code = 130;
	manage_exit(&exit_code);
}

static void	handle_normal_state(void)
{
	int		exit_code;

	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	exit_code = 1;
	manage_exit(&exit_code);
}

void	sigint_manage(int num)
{
	pid_t	child_pid;
	pid_t	reset_pid;

	(void)num;
	child_pid = manage_pid(NULL);
	reset_pid = -1;
	if (g_current_state == STATE_HEREDOC)
		handle_heredoc_state();
	else if (g_current_state == STATE_BLOCKING_CMD)
		handle_blocking_cmd_state(child_pid);
	else if (g_current_state == STATE_NORMAL)
		handle_normal_state();
	manage_pid(&reset_pid);
}
