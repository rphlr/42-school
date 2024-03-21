/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:19:43 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 18:10:04 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_remove_char(char *str, char c)
{
	int		len;
	char	*new_str;
	int		i;
	int		j;

	len = ft_strlen(str);
	new_str = (char *)ft_gc_malloc(len + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] != c)
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static int	handle_special_case(t_global *global, int i)
{
	char	c;
	int		exit_code;

	c = *global->line->token[i];
	if (*global->line->token[i] == '\"' || *global->line->token[i] == '\'')
		global->line->token[i] = ft_remove_char(global->line->token[i], c);
	if (!check_exit_token(global->line->token[i]))
	{
		ft_printf("minishell: exit: %s: numeric argument required\n",
			global->line->token[i]);
		return (255);
	}
	else
	{
		exit_code = ft_atoi(global->line->token[i]);
		if (exit_code < 0 || exit_code > 255)
			exit_code %= 256;
		return (exit_code);
	}
}

static int	manage_token_cases(t_global *global, int i)
{
	if (!global->line->token[i] || (!ft_strcmp(global->line->token[1], "--")
			&& !global->line->token[2]))
		return (global->exit_code);
	else if (global->line->token[i + 1])
	{
		ft_printf("minishell: exit: too many arguments\n");
		return (-1);
	}
	else
	{
		return (handle_special_case(global, i));
	}
}

void	ft_exit(t_global *global)
{
	int	i;

	i = 1;
	global->exit_code = manage_exit(NULL);
	ft_printf("exit\n");
	if (global->line->token[i + 1] && global->line->type[i] == IGNORE)
		i++;
	global->exit_code = manage_token_cases(global, i);
	if (global->exit_code != -1)
		exit(manage_exit(&global->exit_code));
}
