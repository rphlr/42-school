/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_filename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:35:07 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 15:36:28 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_token_continue(t_token *type, int *i)
{
	return (type[*i] != PIPE && type[*i] != SEMICOLON && type[*i] != AND
		&& type[*i] != OR);
}

void	set_filename(t_cmds *head, char **tokens, t_token *type, int *i)
{
	while (tokens[*i] && is_token_continue(type, i))
		handle_token(head, tokens, type, i);
}
