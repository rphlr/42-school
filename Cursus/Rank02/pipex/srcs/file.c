/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:43:42 by rrouille          #+#    #+#             */
/*   Updated: 2023/02/18 15:30:18 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief	Opens the input file based on the mode of input (here_doc or normal
 * 			file input).
 * @param	argv	A pointer to the array of command-line arguments.
 * @param	pipex	A pointer to the t_pipex structure containing file and pipe
 * 					information.
 * @return	void
 */
void	open_input_file(char **argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 8))
		get_heredoc_file(argv[2], pipex);
	else
	{
		pipex->input = open(argv[1], O_RDONLY);
		if (pipex->input < 0)
		{
			ft_printf("%s", INPUT_ERROR);
			exit (1);
		}
	}
}

void	get_heredoc_input(char *limiter, int file)
{
	char	*buf;

	while (true)
	{
		write(1, "pipe heredoc> ", 14);
		buf = get_next_line(0);
		if (buf < 0)
			exit(1);
		if (!ft_strncmp(limiter, buf, ft_strlen(limiter + 1)))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
}

/**
 * @brief	Reads input from the user and saves it to a file until a delimiter
 * 			is entered.
 * @param	limiter	The delimiter string to signal the end of input.
 * @param	pipex	A pointer to the t_pipex structure containing file and pipe
 * 					information.
 * @return	void
 */
void	get_heredoc_file(char *limiter, t_pipex *pipex)
{
	int		file;

	file = open(".heredoc_content", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 1)
	{
		ft_printf("%s", HERE_DOC_ERROR);
		exit (1);
	}
	get_heredoc_input(limiter, file);
	close(file);
	pipex->input = open(".heredoc_content", O_RDONLY);
	if (pipex->input < 0)
	{
		unlink(".heredoc_content");
		ft_printf("%s", HERE_DOC_ERROR);
		exit (1);
	}
}

/**
 * @brief	Opens the output file for writing, either overwriting or appending
 * 			to the file, depending on the has_here_doc flag.
 * @param	argv	A pointer to the output file name string.
 * @param	pipex	A pointer to the t_pipex structure containing file and pipe
 * 					information.
 * @return	void
 */
void	open_output_file(char *argv, t_pipex *pipex)
{
	if (pipex->has_here_doc)
		pipex->output = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		pipex->output = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex->output < 0)
	{
		ft_printf("%s", OUTPUT_ERROR);
		exit (1);
	}
}

/**
 * @brief	Checks the output file descriptor argument and sets the t_pipex
 * 			has_here_doc flag.
 * @param	output_fd_argument	A pointer to the output file descriptor
 * 								argument string.
 * @param	pipex				A pointer to the t_pipex structure containing
 * 								file and pipe information.
 * @return	The length of the output file descriptor argument, depending on the
 * 			presence of the "here_doc" flag.
 */
int	check_command_arguments(char *output_fd_argument, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", output_fd_argument, 9))
	{
		pipex->has_here_doc = 1;
		return (6);
	}
	else
	{
		pipex->has_here_doc = 0;
		return (5);
	}
}
