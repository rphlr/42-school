/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:46:51 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/23 09:54:19 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*epur_str(char *line)
{
	char	*src;
	char	*dst;

	src = line;
	dst = line;
	while (ft_isspace(*src))
		src++;
	while (*src)
	{
		if (ft_isspace(*src))
		{
			while (ft_isspace(*src))
				src++;
			if (!*src)
				break ;
			*dst++ = ' ';
		}
		*dst++ = *src++;
	}
	*dst = '\0';
	return (line);
}
