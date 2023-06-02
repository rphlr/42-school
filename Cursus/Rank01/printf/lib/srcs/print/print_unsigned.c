/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:44:53 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 16:48:12 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function prints the unsigned interger number.
* @param	unsigned_int		The unsigned integer number to print.
* @return	int					The lenght of characters of the printed
*								unsigned integer.
*/
int	print_unsigned(unsigned int num)
{
	int		len;
	char	*numchar;

	len = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
	{
		numchar = ft_unsigned_itoa(num);
		len += print_str(numchar);
		free(numchar);
	}
	return (len);
}
