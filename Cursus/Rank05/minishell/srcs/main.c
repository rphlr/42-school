/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:32:20 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 19:53:38 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ✅: display prompt when minishell is ready to receive input
// ✅: read input
// ✅: parse input
// ✅: Search and launch the right executable (based on the PATH variable
//			or by using relative or absolute path)
// ✅: display output
// ✅: loop
// ✅: Have a working history
// ✅: Do not use more than one global variable, think about it and be ready
//			to explain why you do it.
// ✅: Do not interpret unclosed quotes or unspecified special characters
//			like \ (eg with $’\n’)
// ✅: Handle ' and " (quotes) correctly
// ✅: Handle redirections > >> < <<
// ✅: Handle pipes | correctly
// ✅: Handle environment variables ($ followed by characters)
// ✅: Handle $? (exit code of the previous program)
// ✅: Handle ctrl-C ctrl-D ctrl-\ correctly
// ✅: Implement echo with option ’-n’
// ✅: Implement cd with only a relative or absolute path
// ✅: Implement pwd without any options
// ✅: Implement export without any options
// ✅: Implement unset without any options
// ✅: Implement env without any options and any arguments
// ✅: Implement exit without any options
// ✅: exit
// BONUS
// ✅: Detect Wilcard * (globbing)
// ✅: Detect && and ||

int	main(int ac, char **av, char **envp)
{
	t_global	*global;
	int			err_code;

	(void)ac;
	(void)av;
	global = init_global(envp);
	if (!global)
		return (1);
	set_termios();
	ft_signal();
	err_code = lsh_loop(global);
	exit(err_code);
}
