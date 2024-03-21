/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:49:26 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 15:09:19 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**merge_adjacent_quotes(char **tokens)
{
	char	**temp_tokens;
	char	*current;
	char	*next;

	temp_tokens = tokens;
	while (*temp_tokens && *(temp_tokens + 1))
	{
		current = *temp_tokens;
		next = *(temp_tokens + 1);
		if ((current[0] == '\'' && next[0] == '\'') || (current[0] == '\"'
				&& next[0] == '\"'))
		{
			*temp_tokens = ft_strjoin(current, next);
			*(temp_tokens + 1) = "";
			temp_tokens += 2;
		}
		else
			temp_tokens++;
	}
	return (tokens);
}

t_line	*init_line(char *line, t_global *global)
{
	t_line	*line_struct;
	t_state	error_state;

	line_struct = ft_gc_malloc(sizeof(t_line));
	if (!line_struct)
		return (NULL);
	line_struct->token = parsed_line(line);
	line_struct->token = merge_adjacent_quotes(line_struct->token);
	line_struct->token = split_tokens_with_multiple_quotes(line_struct->token);
	line_struct->type = init_tokens_type(line_struct->token);
	error_state = check_errors(line_struct->type, line_struct->token, global);
	if (error_state)
		return (NULL);
	line_struct->cmds = NULL;
	line_struct->pipe = NULL;
	line_struct->heredoc = NULL;
	line_struct->count = count_types(line_struct->type);
	return (line_struct);
}

// t_env	*init_env(char **envp)
// {
// 	t_env	*head;
// 	t_env	*current;
// 	t_env	*new_item;

// 	head = NULL;
// 	current = NULL;
// 	while (*envp)
// 	{
// 		new_item = ft_gc_malloc(sizeof(t_env));
// 		if (!new_item)
// 			return (NULL);
// 		if (ft_strchr(*envp, '='))
// 		{
// 			new_item->name = ft_strndup(*envp, ft_strchr(*envp, '=') - *envp);
// 			new_item->value = ft_strdup(ft_strchr(*envp, '=') + 1);
// 		}
// 		new_item->next = NULL;
// 		if (!head)
// 		{
// 			head = new_item;
// 			current = head;
// 		}
// 		else
// 		{
// 			current->next = new_item;
// 			current = new_item;
// 		}
// 		envp++;
// 	}
// 	return (head);
// }

t_global	*init_global(char **envp)
{
	t_global	*global;

	global = ft_gc_malloc(sizeof(t_global));
	if (!global)
		return (NULL);
	global->exit_code = 0;
	manage_exit(&global->exit_code);
	global->env = init_env(envp);
	global->line = NULL;
	return (global);
}

void	init_format(t_format *fmt, t_global *global)
{
	fmt->in_double_quotes = 0;
	fmt->in_simple_quotes = 0;
	fmt->i = 0;
	fmt->output = (char *)ft_gc_malloc(biggest_var_value(global->env) + 1);
	if (!fmt->output)
		return ;
}
