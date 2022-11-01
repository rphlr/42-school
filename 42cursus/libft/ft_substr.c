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

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*resp;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
	{
		resp = malloc(1);
		if (!resp)
			return (NULL);
		resp[0] = '\0';
		return (resp);
	}
	if (len > ft_strlen(s))
		resp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		resp = malloc(sizeof(char) * (len + 1));
	if (!resp)
		return (NULL);
	i = 0;
	while (len-- && s[start])
	{
		resp[i] = s[start];
		start++;
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
