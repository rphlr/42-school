/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:30:26 by mvillarr          #+#    #+#             */
/*   Updated: 2023/08/31 14:47:50 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_heredoc_file(void)
{
	int	file;

	file = open(".heredoc_content", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
	{
		ft_printf("Error: failed to open temporary file\n");
		exit(1);
	}
	close(file);
}

void	process_heredoc(char *limiter)
{
	char	*buf;
	int		file;

	g_current_state = STATE_HEREDOC;
	while (true)
	{
		ft_printf("heredoc> ");
		buf = get_next_line(0);
		if (!buf)
		{
			close(file);
			exit(1);
		}
		if (!ft_strncmp(limiter, buf, ft_strlen(limiter)))
			break ;
		file = open(".heredoc_content", O_WRONLY | O_APPEND);
		if (file < 0)
		{
			ft_printf("Error: failed to open temporary file\n");
			exit(1);
		}
		write(file, buf, ft_strlen(buf));
		close(file);
	}
}

void	ft_heredoc(char *filename, char *limiter, int type)
{
	create_heredoc_file();
	process_heredoc(limiter);
	handle_redirection(filename, type);
	g_current_state = STATE_NORMAL;
}

int	handle_redirections(t_redirection *redir, t_global *global)
{
	int	fd;

	fd = 0;
	if (!redir)
		return (0);
	if (redir->type == HEREDOC_REDIRECTION)
	{
		ft_heredoc(redir->filename, redir->limiter, redir->type_hd);
		exit(EXIT_SUCCESS);
	}
	create_file(fd, redir, global);
	return (0);
}

void	handle_redirection(char *filename, int type)
{
	int		fd_final;
	char	*buf;

	is_filename(filename, type);
	fd_final = open_and_check(".heredoc_content", O_RDONLY);
	buf = get_next_line(fd_final);
	while (buf)
	{
		write(STDOUT_FILENO, buf, ft_strlen(buf));
		buf = get_next_line(fd_final);
	}
	close(fd_final);
	unlink(".heredoc_content");
}
