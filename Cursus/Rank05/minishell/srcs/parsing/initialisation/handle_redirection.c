/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:45:08 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 08:10:35 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_heredoc(t_cmds *head, char **tokens, t_token *type, int *i)
{
	head->redir = (t_redirection *)ft_gc_malloc(sizeof(t_redirection));
	if (!head->redir)
		return (0);
	head->redir->type = HEREDOC_REDIRECTION;
	head->redir->limiter = ft_strdup(tokens[*i + 1]);
	if (tokens[*i + 3] && (type[*i + 2] == INPUT || type[*i + 2] == OUTPUT
			|| type[*i + 2] == APPEND))
	{
		head->redir->type_hd = type[*i + 2];
		head->redir->filename = ft_strdup(tokens[*i + 3]);
		*i += 4;
		return (1);
	}
	*i += 2;
	return (1);
}

static int	handle_input(t_cmds *head, char **tokens, int *i)
{
	head->redir = (t_redirection *)ft_gc_malloc(sizeof(t_redirection));
	if (!head->redir)
		return (0);
	head->redir->type = INPUT_REDIRECTION;
	head->redir->filename = ft_strdup(tokens[*i + 1]);
	*i += 2;
	return (1);
}

static int	handle_output(t_cmds *head, char **tokens, int *i)
{
	head->redir = (t_redirection *)ft_gc_malloc(sizeof(t_redirection));
	if (!head->redir)
		return (0);
	head->redir->type = OUTPUT_REDIRECTION;
	head->redir->filename = ft_strdup(tokens[*i + 1]);
	*i += 2;
	return (1);
}

static int	handle_append(t_cmds *head, char **tokens, int *i)
{
	head->redir = (t_redirection *)ft_gc_malloc(sizeof(t_redirection));
	if (!head->redir)
		return (0);
	head->redir->type = APPEND_REDIRECTION;
	head->redir->filename = ft_strdup(tokens[*i + 1]);
	*i += 2;
	return (1);
}

void	handle_token(t_cmds *head, char **tokens, t_token *type, int *i)
{
	if (type[*i] == HEREDOC)
	{
		if (!handle_heredoc(head, tokens, type, i))
			return ;
	}
	else if (type[*i] == INPUT)
	{
		if (!handle_input(head, tokens, i))
			return ;
	}
	else if (type[*i] == OUTPUT)
	{
		if (!handle_output(head, tokens, i))
			return ;
	}
	else if (type[*i] == APPEND)
	{
		if (!handle_append(head, tokens, i))
			return ;
	}
	else
		*i += 1;
}
