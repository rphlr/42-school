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

#include "libft.h"

/**
 * @brief	Determines if a character is a given delimiter.
 * @param	c		Character to check.
 * @param	charset	Delimiter character.
 * @return	true if the character is the delimiter, false otherwise.
 */
static bool	ft_check_sep(char c, char charset)
{
	if (charset == '\0')
		return (c == '\0');
	if (charset == c)
		return (true);
	return (false);
}

/**
 * @brief	Counts the number of substrings in a given string, based on a given
 * 			delimiter.
 * @param	s	Pointer to the string to be split.
 * @param	c	Character to use as the delimiter.
 * @return	Number of substrings in the string.
 */
static char	*ft_print_word(char const *s, char c)
{
	int		len_strs;
	int		i;
	char	*strs;

	i = 0;
	len_strs = 0;
	while (s[len_strs] && !ft_check_sep(s[len_strs], c))
		len_strs++;
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

/**
 * @brief	Extracts a substring from a given string based on a given delimiter.
 * @param	s	Pointer to the string to be split.
 * @param	c	Character to use as the delimiter.
 * @return	Pointer to the extracted substring, or NULL if an error occurred.
 */
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

/**
 * @brief	Fills an array with substrings from a given string, based on a
 * 			given delimiter.
 * @param	strs	Pointer to the array to be filled.
 * @param	s		Pointer to the string to be split.
 * @param	c		Character to use as the delimiter.
 * @param	i		Index of the current position in the array.
 * @return	Pointer to the filled array, or NULL if an error occurred.
 */
char	**ft_fill_array(char **strs, const char *s, char c, int i)
{
	while (*s)
	{
		if (!ft_check_sep(*s, c))
		{
			strs[i] = ft_print_word(s, c);
			if (!strs[i])
			{
				while (i--)
					free(strs[i]);
				free(strs);
				return (NULL);
			}
			i++;
			while (*s && !ft_check_sep(*s, c))
				s++;
		}
		else
			s++;
	}
	strs[i] = 0;
	return (strs);
}

/**
 * @brief	Splits a string into an array of substrings based on a given
 * 			delimiter.
 * @param	s	Pointer to the string to be split.
 * @param	c	Character to use as the delimiter.
 * @return	Pointer to the array of substrings, or NULL if an error occurred.
 */
char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (!strs)
		return (NULL);
	return (ft_fill_array(strs, s, c, i));
}
