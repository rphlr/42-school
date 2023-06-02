/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:45:11 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 12:52:05 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function counts the lenght of a integer number.
* @param	unsigned_int		The unsigned integer number to count lenght.
* @return	int					The lenght of characters of the number.
*/
int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/**
* @notice	This function converts an unsigned interger number to a
*			string.
* @param	unsigned_int		The unsigned integer number to convert.
* @return	string				The converted number.
*/
char	*ft_unsigned_itoa(unsigned int num)
{
	char	*numchar;
	int		len;

	len = num_len(num);
	numchar = (char *)malloc(sizeof(char) * (len + 1));
	if (!numchar)
		return (NULL);
	numchar[len] = '\0';
	while (num != 0)
	{
		numchar[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (numchar);
}
