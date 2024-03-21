/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:40:40 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/16 10:29:41 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_line *line)
{
	char	*path;

	if (line->token[1] != NULL)
	{
		ft_printf("minishell: pwd: too many arguments\n");
		return ;
	}
	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		ft_printf("minishell: pwd: %s\n", strerror(errno));
		return ;
	}
	ft_printf("%s\n", path);
	free(path);
}
