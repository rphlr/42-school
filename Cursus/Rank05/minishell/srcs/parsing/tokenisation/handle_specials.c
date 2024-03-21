/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specials.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:09:07 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 16:50:25 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	handle_pipe(char *token)
{
	if (*(token + 1) == '|')
		return (OR);
	return (PIPE);
}

t_token	handle_input_redirect(char *token)
{
	if (*(token + 1) == '<' && *(token + 2) != '<')
		return (HEREDOC);
	return (INPUT);
}

t_token	handle_output_redirect(char *token)
{
	if (token[0] == '>' && token[1] == '>')
		return (APPEND);
	return (OUTPUT);
}

t_token	handle_dash(char *token)
{
	if (*(token + 1) == '-' && *(token + 2) == '\0')
		return (IGNORE);
	return (OPTIONS);
}
