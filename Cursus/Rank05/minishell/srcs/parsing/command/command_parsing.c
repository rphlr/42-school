/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:42:55 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/28 15:28:37 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_directory(DIR **dir)
{
	*dir = opendir(".");
	if (*dir == NULL)
		return (0);
	return (1);
}

static void	define_home_folder(t_env *env, t_global *global)
{
	if (env == NULL)
		return ;
	global->home_folder = get_env_value("HOME", env);
}

static int	count_original_tokens(t_global *global)
{
	int	count;

	count = 0;
	while (global->line->token[count] != NULL)
		count++;
	return (count);
}

static void	handle_tilde_token(t_global *global, int *token_idx, int *type_idx)
{
	define_home_folder(global->env, global);
	global->line->token[*token_idx] = ft_strdup(get_env_value("HOME",
				global->env));
	if (global->line->token[*token_idx] == NULL)
		global->line->token[*token_idx] = ft_strdup("~");
	(*token_idx)++;
	(*type_idx)++;
}

t_global	*parse_cmd(t_global *global)
{
	int				original_count;
	int				token_idx;
	int				type_idx;

	original_count = count_original_tokens(global);
	token_idx = 0;
	type_idx = 0;
	while (global->line->type[type_idx] != END)
	{
		if (global->line->type[type_idx] == STAR)
			handle_star_token(global, &token_idx, &type_idx, original_count);
		else if (global->line->type[type_idx] == TILDE)
			handle_tilde_token(global, &token_idx, &type_idx);
		else
		{
			token_idx++;
			type_idx++;
		}
	}
	global->line->cmds = init_cmds(global->line->token, global->line->type);
	return (global);
}
