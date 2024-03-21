/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:51:40 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 16:39:51 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_read_history(char *filename)
{
	int			history_fd;
	char		*line;
	t_history	*history_head;

	history_head = NULL;
	history_fd = open(filename, O_CREAT | O_RDWR, 0644);
	if (history_fd == -1)
		ft_printf("minishell: can't open history file\n");
	else
	{
		line = get_next_line(history_fd);
		while (line)
		{
			line = rm_newline(line);
			add_history(line);
			add_to_history_list(&history_head, line);
			line = get_next_line(history_fd);
		}
	}
	return (history_fd);
}

int	add_to_history(t_history **head, char *line, int history_fd)
{
	t_history	*last_entry;

	if (line && ft_strcmp(line, ""))
	{
		last_entry = *head;
		while (last_entry && last_entry->next)
			last_entry = last_entry->next;
		if (!last_entry || ft_strcmp(line, last_entry->line))
		{
			add_history(line);
			ft_putendl_fd(line, history_fd);
			add_to_history_list(head, line);
		}
		if (line_is_wspaces(line))
		{
			free(line);
			return (1);
		}
	}
	return (0);
}

void	loop_prompt(t_global *global, int history_fd)
{
	char		*prompt_clr;
	char		*line;
	t_history	*history_head;

	history_head = NULL;
	while (1)
	{
		prompt_clr = ft_strjoin(get_next_color(), PROMPT);
		line = readline(prompt_clr);
		if (!check_token(line))
			break ;
		if (add_to_history(&history_head, line, history_fd)
			|| !ft_strcmp(line, ""))
			continue ;
		if (line_does_not_exist(global, line))
			continue ;
		free(line);
		global = parse_cmd(global);
		if (command_empty(global))
			continue ;
		run_cmd(global);
	}
}

int	lsh_loop(t_global *global)
{
	int			history_fd;

	history_fd = ft_read_history(".minishell_history");
	loop_prompt(global, history_fd);
	return (global->exit_code);
}
