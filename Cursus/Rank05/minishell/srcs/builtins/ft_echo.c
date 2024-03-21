/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 07:34:38 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 16:27:00 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_option(char *str)
{
	while (*++str)
	{
		if (*str != 'n')
			return (0);
	}
	return (1);
}

static void	echo_print(char *str)
{
	while (*str)
	{
		if (*str == '\\')
		{
			str++;
			ft_printf("%c", *str);
			str++;
			continue ;
		}
		ft_printf("%c", *str++);
	}
}

void	ft_echo(char *cmd, t_global *global)
{
	int	nwln;
	int	i;

	(void)cmd;
	nwln = 1;
	i = 0;
	while (global->line->token[i] && ft_strcmp(global->line->token[i],
			"echo") != 0)
		i++;
	i++;
	while (global->line->token[i] && global->line->token[i][0] == '-'
			&& check_option(global->line->token[i]))
	{
		nwln = 0;
		i++;
	}
	while (global->line->token[i])
	{
		echo_print(global->line->token[i]);
		i++;
		if (global->line->token[i])
			ft_printf(" ");
	}
	if (nwln)
		ft_printf("\n");
}
