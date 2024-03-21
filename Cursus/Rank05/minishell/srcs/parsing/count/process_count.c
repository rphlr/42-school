/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:02:13 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 10:00:38 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_special_token(t_token type)
{
	return (type == INPUT || type == OUTPUT || type == APPEND || type == HEREDOC
		|| type == PIPE || type == SEMICOLON || type == AND || type == OR);
}

static void	increment_special_tokens(t_token type, t_count *count)
{
	if (type == INPUT)
		count->nbr_inputs++;
	else if (type == OUTPUT)
		count->nbr_outputs++;
	else if (type == APPEND)
		count->nbr_appends++;
	else if (type == HEREDOC)
		count->nbr_heredocs++;
	else if (type == PIPE)
		count->nbr_pipes++;
	else if (type == SEMICOLON)
		count->nbr_semicolons++;
	else if (type == AND)
		count->nbr_ands++;
	else if (type == OR)
		count->nbr_ors++;
}

static t_token	*handle_options_and_default(t_token *type, t_count *count)
{
	if (*type == OPTIONS)
	{
		count->nbr_options++;
		return (type);
	}
	count->nbr_tokens++;
	return (type);
}

t_token	*process_token(t_token *type, t_count *count)
{
	if (is_special_token(*type))
	{
		increment_special_tokens(*type, count);
		count->special_cases = true;
	}
	return (handle_options_and_default(type, count));
}
