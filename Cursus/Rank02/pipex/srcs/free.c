/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:42:47 by rrouille          #+#    #+#             */
/*   Updated: 2023/02/18 13:25:29 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief	Closes file descriptors and frees memory associated with the
 * 			t_pipex structure.
 * @param	pipex	A pointer to the t_pipex structure containing file and pipe
 * 					information.
 * @return	void
 */
void	pipe_free(t_pipex *pipex)
{
	close(pipex->input);
	close(pipex->output);
	if (pipex->has_here_doc)
		unlink(".heredoc_content");
	free(pipex->pipe_fds);
	ft_printf("%s\n", MISSING_ENV);
	exit(1);
}

/**
 * @brief	Frees memory associated with the t_pipex structure.
 * @param	pipex	A pointer to the t_pipex structure containing file and pipe
 * 					information.
 * @return	void
 */
void	free_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->command_arg_list[i])
	{
		free(pipex->command_arg_list[i]);
		i++;
	}
	free(pipex->command_arg_list);
	free(pipex->command);
}

/**
 * @brief	Closes file descriptors and frees memory associated with the
 * 			t_pipex structure.
 * @param	pipex	A pointer to the t_pipex structure containing file and pipe
 * 					information.
 * @return	void
 */
void	free_ressources(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->input);
	close(pipex->output);
	if (pipex->has_here_doc)
		unlink(".heredoc_content");
	while (pipex->command_path_list[i])
	{
		free(pipex->command_path_list[i]);
		i++;
	}
	free(pipex->command_path_list);
	free(pipex->pipe_fds);
}
