/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_multiple_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:15:21 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 16:16:10 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_old_to_new_tokens(char **new_tokens, char **tokens, int i,
		int *idx)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		new_tokens[*idx] = tokens[j];
		(*idx)++;
	}
}

static void	split_token_by_quotes(char **new_tokens, char *token, int *idx)
{
	char	*start;
	char	*end;
	char	quote;

	end = token;
	while (*end)
	{
		if (*end == '"' || *end == '\'')
		{
			quote = *end;
			start = end++;
			while (*end && *end != quote)
				end++;
			if (*end == quote)
				end++;
			new_tokens[*idx] = ft_strndup(start, end - start);
			(*idx)++;
			if (*end == ' ' && *(end + 1) == quote)
				end++;
		}
		else
			end++;
	}
}

static int	initialize_variables(char **tokens, int *total_tokens)
{
	*total_tokens = count_total_tokens(tokens);
	return (-1);
}

static char	**process_token_with_multiple_quotes(char **tokens, int i,
		int *total_tokens)
{
	int		new_tokens_count;
	char	**new_tokens;
	int		idx;

	new_tokens_count = count_new_tokens(tokens[i]);
	if (new_tokens_count == 0)
		return (tokens);
	new_tokens = (char **)ft_gc_malloc((*total_tokens + new_tokens_count + 1)
			* sizeof(char *));
	if (!new_tokens)
		return (NULL);
	idx = 0;
	copy_old_to_new_tokens(new_tokens, tokens, i, &idx);
	split_token_by_quotes(new_tokens, tokens[i], &idx);
	while (++i < *total_tokens)
	{
		new_tokens[idx++] = tokens[i];
	}
	new_tokens[idx] = NULL;
	*total_tokens += new_tokens_count - 1;
	return (new_tokens);
}

char	**split_tokens_with_multiple_quotes(char **tokens)
{
	int	total_tokens;
	int	i;

	i = initialize_variables(tokens, &total_tokens);
	while (++i < total_tokens)
	{
		if (count_quotes_in_token(tokens[i]) > 2)
		{
			tokens = process_token_with_multiple_quotes(tokens, i,
					&total_tokens);
			if (!tokens)
				return (NULL);
		}
	}
	return (tokens);
}
