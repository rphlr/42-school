/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_substrings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:09:18 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 17:12:43 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*skip_spaces(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

static char	*handle_quotes(char *line)
{
	char	quote;

	quote = *line;
	line++;
	while (*line && *line != quote)
		line++;
	if (*line)
		line++;
	return (line);
}

static char	*handle_word(char *line)
{
	while (*line && *line != ' ' && *line != '\t' && *line != '"'
		&& *line != '\'')
		line++;
	return (line);
}

int	count_substrings(char *line)
{
	int	count;

	count = 0;
	line = skip_spaces(line);
	while (*line)
	{
		if (*line == '"' || *line == '\'')
			line = handle_quotes(line);
		else if (*line != ' ' && *line != '\t')
			line = handle_word(line);
		else
			line++;
		count++;
	}
	return (count);
}
