/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:52 by rrouille          #+#    #+#             */
/*   Updated: 2023/02/18 15:56:31 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief	Closes the unused ends of the communication pipes.
 * @param	pipex	A pointer to the t_pipex structure containing file and pipe
 * 					information.
 * @return	void
 */
void	close_communication(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipes_count))
	{
		close(pipex->pipe_fds[i]);
		i++;
	}
}

/**
 * @brief	Creates the required pipes for communication between commands.
 * @param	pipex	A pointer to the t_pipex structure containing file and
 * 					pipe information.
 * @return	void
 */
void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->command_count)
	{
		if (pipe(pipex->pipe_fds + 2 * i) < 0)
			free_ressources(pipex);
		i++;
	}
}

/**
 * @brief	Sets up pipe communication between the specified input and output
 * 			file descriptors.
 * @param	input_fd	The input file descriptor to be used for the pipe
 * 						communication.
 * @param	output_fd	The output file descriptor to be used for the pipe
 * 						communication.
 * @return	void
 */
void	setup_pipe_communication(int input_fd, int output_fd)
{
	dup2(input_fd, 0);
	dup2(output_fd, 1);
}

/**
 * @brief	Prints an error message if the specified command does not exist.
 * @param	pipex	The t_pipex structure containing information about the
 * 					command to be run.
 */
void	command_error(t_pipex pipex)
{
	char	*error;

	if (!pipex.command)
	{
		error = ft_strjoin(pipex.command_arg_list[0],
				" command does not exists.\n\e[K");
		error = ft_strjoin("\e[31m", error);
		write(2, error, ft_strlen(error));
		free_pipex(&pipex);
		exit(1);
	}
}

/**
 * @brief	Runs the specified command with the appropriate input and output.
 * @param	pipex	A t_pipex structure containing file and pipe information.
 * @param	argv	A pointer to the array of command-line arguments.
 * @param	env		A pointer to the array of environment variables.
 * @return	void
 */
void	run_commands(t_pipex pipex, char **argv, char **env)
{
	pipex.pid = fork();
	if (!pipex.pid)
	{
		if (pipex.i == 0)
			setup_pipe_communication(pipex.input, pipex.pipe_fds[1]);
		else if (pipex.i == pipex.command_count - 1)
			setup_pipe_communication(pipex.pipe_fds[2 * pipex.i - 2],
				pipex.output);
		else
			setup_pipe_communication(pipex.pipe_fds[2 * pipex.i - 2],
				pipex.pipe_fds[2 * pipex.i + 1]);
		close_communication(&pipex);
		pipex.command_arg_list = ft_split(argv[2 + pipex.has_here_doc
				+ pipex.i], ' ');
		pipex.command = get_command_path(pipex.command_path_list,
				pipex.command_arg_list[0]);
		command_error(pipex);
		execve(pipex.command, pipex.command_arg_list, env);
	}
}
