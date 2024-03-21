/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:58:07 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/31 16:30:04 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_and_wait(int **fds, int num_cmds)
{
	int	i;

	i = -1;
	while (++i < num_cmds - 1)
	{
		close(fds[i][0]);
		close(fds[i][1]);
	}
	i = -1;
	while (++i < num_cmds)
		wait(NULL);
}

void	create_file(int fd, t_redirection *redir, t_global *global)
{
	fd = -1;
	if (redir->type == OUTPUT_REDIRECTION)
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == APPEND_REDIRECTION)
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir->type == INPUT_REDIRECTION)
		fd = open(redir->filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("minishell: %s: %s\n", redir->filename, strerror(errno));
		global->exit_code = 1;
		exit(EXIT_FAILURE);
	}
	if (redir->type == OUTPUT_REDIRECTION || redir->type == APPEND_REDIRECTION)
		dup2(fd, STDOUT_FILENO);
	else if (redir->type == INPUT_REDIRECTION)
		dup2(fd, STDIN_FILENO);
	close (fd);
}

void	is_filename(char *filename, int type)
{
	int		fd_final;
	int		flags;

	fd_final = 0;
	flags = 0;
	if (filename)
	{
		flags = O_CREAT | O_WRONLY;
		if (type == APPEND)
			flags |= O_APPEND;
		else if (type == OUTPUT)
			flags |= O_TRUNC;
		fd_final = open_and_check(filename, flags);
		dup2(fd_final, STDOUT_FILENO);
		close(fd_final);
	}
}

int	open_and_check(char *filename, int flags)
{
	int	fd;

	fd = open(filename, flags, 0644);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", filename);
		exit(1);
	}
	return (fd);
}
