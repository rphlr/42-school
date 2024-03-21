/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:58:34 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 15:50:10 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmds	*new_cmd_init(void)
{
	t_cmds	*new_cmd;

	new_cmd = (t_cmds *)ft_gc_malloc(sizeof(t_cmds));
	if (!new_cmd)
		return (NULL);
	new_cmd->cmd = NULL;
	new_cmd->redir = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

static void	add_cmd_to_list(t_cmds **head, t_cmds **current, t_cmds *new_cmd)
{
	if (*head == NULL)
	{
		*head = new_cmd;
		*current = *head;
	}
	else
	{
		(*current)->next = new_cmd;
		*current = new_cmd;
	}
}

static char	*build_full_cmd(char **tokens, t_token *type, int *i)
{
	char	*full_cmd;
	char	*temp;

	full_cmd = ft_strdup(tokens[*i]);
	if (tokens[*i + 1] != NULL)
		full_cmd = ft_strjoin(full_cmd, " ");
	while (tokens[*i + 1] != NULL && type[*i + 1] != PIPE
		&& type[*i + 1] != SEMICOLON && type[*i + 1] != AND
		&& type[*i + 1] != OR && type[*i + 1] != HEREDOC
		&& type[*i + 1] != INPUT && type[*i + 1] != OUTPUT
		&& type[*i + 1] != APPEND)
	{
		(*i)++;
		temp = full_cmd;
		full_cmd = ft_strjoin(temp, tokens[*i]);
		if (tokens[*i + 1] != NULL)
			full_cmd = ft_strjoin(full_cmd, " ");
	}
	return (full_cmd);
}

t_cmds	*init_cmds(char **tokens, t_token *type)
{
	t_cmds	*head;
	t_cmds	*current;
	int		i;
	t_cmds	*new_cmd;

	head = NULL;
	current = NULL;
	i = 0;
	while (tokens[i])
	{
		new_cmd = new_cmd_init();
		if (!new_cmd)
			return (NULL);
		new_cmd->cmd = build_full_cmd(tokens, type, &i);
		add_cmd_to_list(&head, &current, new_cmd);
		i++;
		if (type[i] == PIPE || type[i] == SEMICOLON || type[i] == AND
			|| type[i] == OR)
			i++;
	}
	i = 0;
	set_filename(head, tokens, type, &i);
	return (head);
}
