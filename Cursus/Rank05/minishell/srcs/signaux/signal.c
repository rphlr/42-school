/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:32:41 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/31 14:53:10 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// c_lflag = 1011 0001      1011 0001
// ECHOCTL = 0000 0001 ~ -> 1111 1110  &
//          0000 0001      1011 0000
// clean ctr-c dans le terminal

static void	handle_sigpipe(int signo)
{
	(void)signo;
}

// static void	sigint_manage(int num)
// {
// 	int		exit_code;
// 	pid_t	child_pid;
// 	pid_t	reset_pid;

// 	(void)num;
// 	child_pid = manage_pid(NULL);
// 	reset_pid = -1;
// 	if (g_current_state == STATE_HEREDOC)
// 	{
// 		exit_code = 1;
// 		manage_exit(&exit_code);
// 		return ;
// 	}
// 	else if (g_current_state == STATE_BLOCKING_CMD)
// 	{
// 		ft_printf("\n");
// 		if (child_pid > 0)
// 			kill(child_pid, SIGINT);
// 		exit_code = 130;
// 	}
// 	else if (g_current_state == STATE_NORMAL)
// 	{
// 		ft_printf("\n");
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 		exit_code = 1;
// 	}
// 	manage_exit(&exit_code);
// 	manage_pid(&reset_pid);
// }

void	set_termios(void)
{
	static struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &term);
}

void	ft_signal(void)
{
	struct sigaction	s;

	s.sa_handler = SIG_IGN;
	sigemptyset(&s.sa_mask);
	s.sa_flags = 0;
	sigaction(SIGQUIT, &s, NULL);
	s.sa_handler = sigint_manage;
	sigaction(SIGINT, &s, NULL);
	s.sa_handler = handle_sigpipe;
	sigaction(SIGPIPE, &s, NULL);
}
