/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:42:00 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 16:46:53 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_state(t_state state, char **tokens)
{
	if (state == QUOTE_ERROR)
		ft_printf(ERR_QUOTE);
	else if (state == DQUOTE_ERROR)
		ft_printf(ERR_DQUOTE);
	else if (state == PIPE_ERROR)
		ft_printf(ERR_PARSE, "|");
	else if (state == INPUT_ERROR)
		handle_input_error(tokens);
	else if (state == OUTPUT_ERROR)
		handle_output_error(tokens);
	else if (state == APPEND_ERROR)
		handle_append_error(tokens);
	else if (state == HEREDOC_ERROR)
		handle_heredoc_error(tokens);
	else if (state == AND_ERROR)
		handle_and_error(tokens);
	else if (state == OR_ERROR)
		ft_printf(ERR_PARSE, "||");
	else if (state == SEMICOLON_ERROR)
		ft_printf(ERR_PARSE, ";");
	else if (state == OPTIONS_ERROR)
		ft_printf(ERR_OPTION, tokens[0]);
}

t_state	check_errors(t_token *type, char **tokens, t_global *global)
{
	t_state	state;

	state = ft_error(type, tokens, global);
	ft_check_state(state, tokens);
	if (state != VALID)
		return (state);
	return (VALID);
}
