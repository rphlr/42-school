/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:16:25 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 10:36:14 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_dollar_question(char **token, t_global *global,
		char *output, int *i)
{
	char	*num;

	global->exit_code = manage_exit(NULL);
	num = ft_itoa(global->exit_code);
	while (*num)
		output[(*i)++] = *num++;
	(*token)++;
}

static void	handle_dollar_varname(char **token, t_global *global, char *output,
		int *i)
{
	char	*var_name;
	char	*var_value;

	var_name = extract_variable_name(*token);
	if (ft_strlen(var_name) > 0)
	{
		var_value = get_env_value(var_name, global->env);
		while (var_value && *var_value)
			output[(*i)++] = *var_value++;
		*token += ft_strlen(var_name);
	}
	else
		output[(*i)++] = '$';
}

void	handle_dollar(char **token, t_global *global, t_format *fmt)
{
	if (fmt->in_simple_quotes)
	{
		fmt->output[fmt->i++] = **token;
		return ;
	}
	(*token)++;
	if (**token == '?')
		handle_dollar_question(token, global, fmt->output, &fmt->i);
	else
		handle_dollar_varname(token, global, fmt->output, &fmt->i);
}
