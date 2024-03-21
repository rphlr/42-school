/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:47:02 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 16:48:41 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_input_error(char **tokens)
{
	if (!ft_strcmp(tokens[0], "<"))
		ft_printf(ERR_PARSE, "newline");
	else
		ft_printf(ERR_PARSE, "<");
}

void	handle_output_error(char **tokens)
{
	if (!ft_strcmp(tokens[0], ">"))
		ft_printf(ERR_PARSE, "newline");
	else
		ft_printf(ERR_PARSE, ">");
}

void	handle_append_error(char **tokens)
{
	if (!ft_strcmp(tokens[0], ">>"))
		ft_printf(ERR_PARSE, "newline");
	else
		ft_printf(ERR_PARSE, ">>");
}

void	handle_heredoc_error(char **tokens)
{
	if (!ft_strcmp(tokens[0], "<<"))
		ft_printf(ERR_PARSE, "newline");
	else
		ft_printf(ERR_PARSE, "<<");
}

void	handle_and_error(char **tokens)
{
	if (!ft_strcmp(tokens[0], "&"))
		ft_printf(ERR_PARSE, "&");
	else
		ft_printf(ERR_PARSE, "&&");
}
