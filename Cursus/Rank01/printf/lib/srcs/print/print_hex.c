/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:05:36 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 13:06:24 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function counts the lenght of an unsigned integer number converted
*			into a hexadecimal.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @return	int					The lenght of characters of the hexadecimal number.
*/
int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

/**
* @notice	This function converts an unsigned integer number into hexadecimal.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @param	const_char			The conversion needed ('x' for lowercase and 'X'
*								for uppercase).
* @return	void				No return value needed now.
*/
void	put_hex(unsigned int num, const char conversion)
{
	if (num >= 16)
	{
		put_hex(num / 16, conversion);
		put_hex(num % 16, conversion);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (conversion == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (conversion == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

/**
* @notice	This function checks an unsigned integer number, converts it into
*			hexadecimal, prints it and counts its lenght.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @param	const_char			The conversion needed ('x' for lowercase and 'X'
*								for uppercase).
* @return	int					The lenght of characters of the hexadecimal number.
*/
int	print_hex(unsigned int num, const char conversion)
{
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
		put_hex(num, conversion);
	return (hex_len(num));
}
