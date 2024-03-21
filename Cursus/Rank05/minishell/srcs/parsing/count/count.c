/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:38:18 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/29 09:21:18 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_count	*initialize_count(void)
{
	t_count	*count;

	count = ft_gc_malloc(sizeof(t_count));
	if (!count)
		return (NULL);
	count->special_cases = false;
	return (count);
}

t_count	*count_types(t_token *type)
{
	t_count	*count;

	count = initialize_count();
	if (!count)
		return (NULL);
	while (*type != END)
	{
		type = process_token(type, count);
		type++;
	}
	count->nbr_cmds = count->nbr_pipes + 1;
	return (count);
}
