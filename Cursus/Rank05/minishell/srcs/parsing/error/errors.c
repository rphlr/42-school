/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:45:19 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 14:27:10 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_state	*get_error_table(void)
{
	t_state	*error_table;

	error_table = ft_gc_malloc(9 * sizeof(t_state));
	if (!error_table)
		return (NULL);
	error_table[PIPE] = PIPE_ERROR;
	error_table[INPUT] = INPUT_ERROR;
	error_table[OUTPUT] = OUTPUT_ERROR;
	error_table[APPEND] = APPEND_ERROR;
	error_table[HEREDOC] = HEREDOC_ERROR;
	error_table[AND] = AND_ERROR;
	error_table[OR] = OR_ERROR;
	error_table[SEMICOLON] = SEMICOLON_ERROR; //(SEMICOLON = 8)
	return (error_table);
}

static char	*handle_env_variable(char *token, char *output, int *i,
		t_global *global)
{
	char	*var_name;
	char	*var_value;
	char	*num;

	if (*token == '?')
	{
		global->exit_code = manage_exit(NULL);
		num = ft_itoa(global->exit_code);
		while (*num)
			output[(*i)++] = *num++;
		return (token + 1);
	}
	var_name = extract_variable_name(token);
	if (ft_strlen(var_name) > 0)
	{
		var_value = get_env_value(var_name, global->env);
		if (var_value)
		{
			while (*var_value)
				output[(*i)++] = *var_value++;
		}
		return (token + ft_strlen(var_name));
	}
	output[(*i)++] = '$';
	return (token);
}

static char	*handle_token_static(char *token, t_format *fmt, t_global *global)
{
	while (*token)
	{
		if (is_quotes(*token, &fmt->in_double_quotes, &fmt->in_simple_quotes))
			token++;
		else if (*token == '$' && !(fmt->in_simple_quotes))
			token = handle_env_variable(++token, fmt->output, &fmt->i, global);
		else
			fmt->output[fmt->i++] = *token++;
	}
	return (fmt->output);
}

static char	*format_token(char *token, t_global *global)
{
	t_format	fmt;

	init_format(&fmt, global);
	if (!fmt.output)
		return (NULL);
	fmt.output = handle_token_static(token, &fmt, global);
	fmt.output[fmt.i] = '\0';
	return (fmt.output);
}

t_state	ft_error(t_token *type, char **tokens, t_global *global)
{
	int		nbr_quote;
	int		nbr_dquote;
	t_state	*error_table;
	t_state	token_check_result;

	nbr_quote = 0;
	nbr_dquote = 0;
	error_table = get_error_table();
	token_check_result = check_token_errors(type, tokens, error_table);
	if (token_check_result != VALID)
		return (token_check_result);
	while (*type != END)
	{
		*tokens = format_token(*tokens, global);
		nbr_quote += (*type == NOT_CLOSED_QUOTE) + 2 * (*type == CLOSED_QUOTE);
		nbr_dquote += (*type == NOT_CLOSED_DQUOTE) + 2
			* (*type == CLOSED_DQUOTE);
		type++;
		tokens++;
	}
	if (nbr_quote % 2 != 0)
		return (QUOTE_ERROR);
	if (nbr_dquote % 2 != 0)
		return (DQUOTE_ERROR);
	return (VALID);
}
