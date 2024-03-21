/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:02:47 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 08:39:20 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	check_closed_quotes(char *token, char closing_char, int j)
{
	while (token[j] != closing_char && token[j - 1] != '\\')
	{
		if (!token[j++])
		{
			if (closing_char == '\'')
				return (NOT_CLOSED_QUOTE);
			return (NOT_CLOSED_DQUOTE);
		}
	}
	if (token[j] == closing_char)
	{
		if (closing_char == '\'')
			return (CLOSED_QUOTE);
		return (CLOSED_DQUOTE);
	}
	if (closing_char == '\'')
		return (NOT_CLOSED_QUOTE);
	return (NOT_CLOSED_DQUOTE);
}

static t_token	handle_quotes(char *token)
{
	char	closing_char;
	int		j;

	j = 1;
	if (*token == '\'')
		closing_char = '\'';
	else
		closing_char = '\"';
	return (check_closed_quotes(token, closing_char, j));
}

static t_token	handle_special_char(char c, char *token)
{
	if (c == '|')
		return (handle_pipe(token));
	else if (c == '<')
		return (handle_input_redirect(token));
	else if (c == '>')
		return (handle_output_redirect(token));
	else if (!ft_strcmp(token, ";"))
		return (SEMICOLON);
	else if (!ft_strcmp(token, "&&"))
		return (AND);
	else if (c == '$')
		return (DOLLAR);
	else if (c == '~')
		return (TILDE);
	else if (c == '*')
		return (STAR);
	else if (c == '\'' || c == '\"')
		return (handle_quotes(token));
	else if (c == '-')
		return (handle_dash(token));
	return (WORD);
}

static t_token	get_token_type(char *token)
{
	char	c;

	if (!token || !*token)
		return (END);
	c = *token;
	return (handle_special_char(c, token));
}

t_token	*init_tokens_type(char **tokens)
{
	t_token	*type;
	int		i;

	type = ft_gc_malloc(sizeof(t_token) * (ft_tablen(tokens) + 1));
	if (!type)
		return (NULL);
	i = -1;
	while (tokens[++i])
		type[i] = get_token_type(tokens[i]);
	type[ft_tablen(tokens)] = END;
	return (type);
}
