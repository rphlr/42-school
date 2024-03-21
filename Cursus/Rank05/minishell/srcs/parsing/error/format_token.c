/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:14:25 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 15:00:13 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quotes(char c, int *in_double_quotes, int *in_simple_quotes)
{
	if (c == '\'' && !(*in_double_quotes))
	{
		*in_simple_quotes = !(*in_simple_quotes);
		return (1);
	}
	if (c == '\"' && !(*in_simple_quotes))
	{
		*in_double_quotes = !(*in_double_quotes);
		return (1);
	}
	return (0);
}

static void	init_vars(t_global *global, t_format *fmt)
{
	fmt->in_double_quotes = 0;
	fmt->in_simple_quotes = 0;
	fmt->i = 0;
	fmt->output = (char *)ft_gc_malloc(biggest_var_value(global->env) + 1);
	if (!fmt->output)
		return ;
}

static void	process_tokens(char *token, t_global *global, t_format *fmt)
{
	if (!is_quotes(*token, &fmt->in_double_quotes, &fmt->in_simple_quotes))
	{
		if (*token == '$')
			handle_dollar(&token, global, fmt);
		else
			fmt->output[fmt->i++] = *token;
	}
}

char	*format_token(char *token, t_global *global)
{
	t_format	*fmt;

	fmt = (t_format *)ft_gc_malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	init_vars(global, fmt);
	if (!fmt->output)
		return (NULL);
	while (*token)
	{
		process_tokens(token, global, fmt);
		token++;
	}
	fmt->output[fmt->i] = '\0';
	return (fmt->output);
}
