/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:32:35 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 15:12:39 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	count_substrings(char *line)
// {
// 	int	count;

// 	count = 0;
// 	while (*line && (*line == ' ' || *line == '\t'))
// 		line++;
// 	while (*line)
// 	{
// 		if (*line == '"' || *line == '\'')
// 		{
// 			count++;
// 			line++;
// 			while (*line && (*line != '"' && *line != '\''))
// 				line++;
// 			if (*line)
// 				line++;
// 		}
// 		else if (*line != ' ' && *line != '\t')
// 		{
// 			count++;
// 			while (*line && *line != ' ' && *line != '\t' && *line != '"'
// 				&& *line != '\'')
// 				line++;
// 		}
// 		else
// 			line++;
// 	}
// 	return (count);
// }

static char	extract_quoted_string(char **line_pointer, char **output)
{
	char	*line;
	char	quote;
	char	*start;
	int		nbr_backslash;

	line = *line_pointer;
	quote = *line++;
	start = line - 1;
	nbr_backslash = 0;
	while (*line && (*line != quote || *(line - 1) == '\\'))
	{
		if (*line == '\\' && *(line - 1) == '\\')
			nbr_backslash++;
		line++;
	}
	if (nbr_backslash % 2 == 1)
		line--;
	*output = ft_strndup(start, line - start + 1);
	*line_pointer = line + 1;
	return (quote);
}

static char	*extract_unquoted_string(char **line_pointer)
{
	char	*line;
	char	*start;

	line = *line_pointer;
	start = line;
	while (*line && *line != ' ' && *line != '"' && *line != '\'')
		line++;
	*line_pointer = line;
	return (ft_strndup(start, line - start));
}

static void	skip_spaces(char **line)
{
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
}

static char	*merge_and_extract_quotes(char **line, char quote_used)
{
	char	*current_string;
	char	*next_string;
	char	*merged_string;

	extract_quoted_string(line, &current_string);
	while (*((*line) - 1) == quote_used && (**line != ' ' && **line != '\t'
			&& **line != '\0'))
	{
		extract_quoted_string(line, &next_string);
		merged_string = ft_strjoin(current_string, next_string);
		current_string = merged_string;
	}
	return (current_string);
}

char	**parsed_line(char *line)
{
	char	**result;
	int		index;
	char	*temp_line;

	temp_line = line;
	result = (char **)ft_gc_malloc(sizeof(char *) * (count_substrings(line)
				+ 2));
	if (!result)
		return (NULL);
	index = 0;
	while (*line)
	{
		skip_spaces(&line);
		if ((*line == '"' || *line == '\'') && (line == temp_line || *(line
					- 1) != '\\'))
			result[index++] = merge_and_extract_quotes(&line, *line);
		else if (*line)
			result[index++] = extract_unquoted_string(&line);
	}
	result[index] = NULL;
	return (result);
}
