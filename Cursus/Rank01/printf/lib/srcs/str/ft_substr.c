/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:30:08 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/30 17:59:47 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_substr(const char *s1, unsigned int start, size_t len)
{
	char			*resp;
	size_t			i;

	if (len == 0 || start > ft_strlen(s1))
	{
		resp = malloc(1);
		if (!resp)
			return (NULL);
		resp[0] = '\0';
		return (resp);
	}
	if (len > ft_strlen(s1))
		resp = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	else
		resp = malloc(sizeof(char) * (len + 1));
	if (!resp)
		return (NULL);
	i = 0;
	while (len-- && s1[start])
	{
		resp[i++] = s1[start];
		start++;
	}
	resp[i] = '\0';
	return (resp);
}
