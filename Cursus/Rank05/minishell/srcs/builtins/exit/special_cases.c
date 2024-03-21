/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:08:39 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/30 18:10:18 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_less_than_limit(char *arg, char *limit_str, int start)
{
	while (arg[start])
	{
		if (arg[start] > limit_str[start])
			return (false);
		start++;
	}
	return (true);
}

static bool	is_valid_length_and_content(char *arg, bool is_negative)
{
	char	*limit_str;
	int		i;

	if (is_negative)
	{
		limit_str = "9223372036854775808";
		i = 1;
	}
	else
	{
		limit_str = "9223372036854775807";
		i = 0;
	}
	if (ft_strlen(arg) - is_negative > ft_strlen(limit_str))
		return (false);
	if (ft_strlen(arg) - is_negative < ft_strlen(limit_str))
		return (true);
	return (is_less_than_limit(arg, limit_str, i));
}

static bool	has_valid_characters(char *arg)
{
	while (*arg && (ft_isdigit(*arg) || *arg == ' ' || *arg == '\"'
			|| *arg == '\''))
		arg++;
	return (!(*arg));
}

bool	check_exit_token(char *arg)
{
	bool	is_negative;
	char	*tmp;

	tmp = arg;
	is_negative = false;
	if (*tmp == '-')
	{
		is_negative = true;
		tmp++;
	}
	else if (*tmp == '+')
		tmp++;
	if (!has_valid_characters(tmp))
		return (false);
	return (is_valid_length_and_content(arg, is_negative));
}
