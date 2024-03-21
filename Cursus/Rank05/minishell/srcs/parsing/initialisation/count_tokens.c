/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:17:59 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 16:18:19 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_total_tokens(char **tokens)
{
	int	total_tokens;

	total_tokens = 0;
	while (tokens[total_tokens])
		total_tokens++;
	return (total_tokens);
}

int	count_quotes_in_token(char *token)
{
	int	quote_count;
	int	j;

	quote_count = 0;
	j = -1;
	while (token[++j])
		if (token[j] == '"' || token[j] == '\'')
			quote_count++;
	return (quote_count);
}

int	count_new_tokens(char *token)
{
	int		new_tokens_count;
	char	*end;
	char	quote;

	new_tokens_count = 0;
	end = token;
	while (*end)
	{
		if (*end == '"' || *end == '\'')
		{
			quote = *end;
			end++;
			while (*end && *end != quote)
				end++;
			if (*end == quote)
				end++;
			if (*end == ' ' && *(end + 1) == quote)
				new_tokens_count++;
		}
		else
			end++;
	}
	return (new_tokens_count);
}
