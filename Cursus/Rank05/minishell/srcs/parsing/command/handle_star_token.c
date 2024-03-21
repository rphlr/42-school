/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_star_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:26:09 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 15:17:37 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	read_directory_entries(DIR *dir, char *entries_array[])
{
	struct dirent	*entry;
	int				entries_count;

	entries_count = 0;
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_name[0] != '.' && entries_count < 1000)
		{
			entries_array[entries_count] = ft_strdup(entry->d_name);
			entries_count++;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (entries_count);
}

static void	fill_new_arrays(t_global *global, char *entries_array[],
		int entries_count, t_format *params)
{
	int	i;
	int	j;

	j = -1;
	while (++j < *(params->token_idx))
	{
		params->new_tokens[j] = global->line->token[j];
		params->new_types[j] = global->line->type[j];
	}
	i = -1;
	while (++i < entries_count)
	{
		params->new_tokens[*(params->token_idx) + i] = entries_array[i];
		params->new_types[*(params->token_idx) + i] = WORD;
	}
	j = *(params->token_idx);
	while (++j < params->original_count)
	{
		params->new_tokens[j + entries_count - 1] = global->line->token[j];
		params->new_types[j + entries_count - 1] = global->line->type[j];
	}
	params->new_tokens[params->original_count + entries_count - 1] = NULL;
	params->new_types[params->original_count + entries_count - 1] = END;
}

static void	handle_if_block(t_global *global, int *token_idx)
{
	global->line->token[*token_idx] = ft_strdup("*");
	(*token_idx)++;
}

static void	handle_else_block(t_global *global, int *token_idx,
		int original_count, DIR *dir)
{
	t_format	*params;
	char		*entries_array[1000];
	char		**new_tokens;
	t_token		*new_types;

	params = (t_format *)ft_gc_malloc(sizeof(t_format));
	params->entries_count = read_directory_entries(dir, entries_array);
	new_tokens = (char **)ft_gc_malloc(sizeof(char *) * (original_count
				+ params->entries_count));
	new_types = (t_token *)ft_gc_malloc(sizeof(t_token) * (original_count
				+ params->entries_count));
	if (!new_tokens || !new_types || !params)
		return ;
	fill_new_arrays(global, entries_array, params->entries_count,
		&(t_format){.new_tokens = new_tokens, .new_types = new_types,
		.token_idx = token_idx, .original_count = original_count});
	global->line->token = new_tokens;
	global->line->type = new_types;
	*token_idx += params->entries_count;
}

void	handle_star_token(t_global *global, int *token_idx, int *type_idx,
		int original_count)
{
	DIR		*dir;

	if (!open_directory(&dir))
		handle_if_block(global, token_idx);
	else
		handle_else_block(global, token_idx, original_count, dir);
	(*type_idx)++;
}
