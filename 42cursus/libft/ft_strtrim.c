/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:56:15 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/04 12:56:15 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_check_sep(char c, char const *set)
{
	if (*set == '\0')
		return (c == '\0');
	if (*set == c)
		return (true);
	return (false);
}

static int	ft_strlen_charset(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i] && !ft_check_sep(str[i], set))
		i++;
	return (i);
}

static char	*ft_print_word(char const *str, char const *set)
{
	int		len_strs;
	int		i;
	char	*strs;

	i = 0;
	len_strs = ft_strlen_charset(str, set);
	strs = malloc(sizeof(char) * (len_strs + 1));
	if (!(strs))
		return (NULL);
	while (i < len_strs)
	{
		strs[i] = str[i];
		i++;
	}
	strs[i] = '\0';
	return (strs);
}

static int	ft_count_strings(char const *str, char const *set)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_check_sep(str[i], set))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_check_sep(str[i], set))
			i++;
	}
	return (count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (ft_count_strings(s1, set) + 1));
	if (!(strs))
		return (NULL);
	while (*s1 != '\0')
	{
		while (*s1 != '\0' && ft_check_sep(*s1, set))
			s1++;
		if (*s1 != '\0')
		{
			strs = ft_print_word(s1, set);
			i++;
		}
		while (*s1 != '\0' && !ft_check_sep(*s1, set))
			s1++;
	}
	strs[i] = 0;
	return (strs);
}
