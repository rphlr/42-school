/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:40 by rrouille          #+#    #+#             */
/*   Updated: 2023/02/18 15:24:07 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief	Finds the PATH environment variable in the array of environment
 * 			variables and returns its value.
 * @param	env		A pointer to the array of environment variables.
 * @return	A pointer to the value of the PATH environment variable.
 */
char	*find_path_env(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

/**
 * @brief	Gets the full path of the command executable.
 * @param	path_var	A pointer to the PATH environment variable split into
 * 						an array of paths.
 * @param	command		The name of the command executable.
 * @return	A pointer to the full path of the command executable, or NULL if
 * 			not found.
 */
char	*get_command_path(char **path_var, char *command)
{
	char	*temp_path;
	char	*command_path;

	while (*path_var)
	{
		temp_path = ft_strjoin(*path_var, "/");
		command_path = ft_strjoin(temp_path, command);
		free(temp_path);
		if (access(command_path, 0) == 0)
			return (command_path);
		free(command_path);
		path_var++;
	}
	return (NULL);
}
