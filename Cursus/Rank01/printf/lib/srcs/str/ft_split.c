/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:06 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/30 14:47:27 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static bool	ft_check_sep(char c, char charset)
{
	if (charset == '\0')
		return (c == '\0');
	if (charset == c)
		return (true);
	return (false);
}

static int	ft_strlen_charset(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !ft_check_sep(s[i], c))
		i++;
	return (i);
}

static char	*ft_print_word(char const *s, char c)
{
	int		len_strs;
	int		i;
	char	*strs;

	i = 0;
	len_strs = ft_strlen_charset(s, c);
	strs = malloc(sizeof(char) * (len_strs + 1));
	if (!(strs))
		return (NULL);
	while (i < len_strs)
	{
		strs[i] = s[i];
		i++;
	}
	strs[i] = '\0';
	return (strs);
}

static int	ft_count_strings(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_check_sep(s[i], c))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && !ft_check_sep(s[i], c))
			i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (!(strs))
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && ft_check_sep(*s, c))
			s++;
		if (*s != '\0')
		{
			strs[i] = ft_print_word(s, c);
			i++;
		}
		while (*s != '\0' && !ft_check_sep(*s, c))
			s++;
	}
	strs[i] = 0;
	return (strs);
}
