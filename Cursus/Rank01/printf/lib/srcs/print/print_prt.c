/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:59:51 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 16:42:51 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function counts the lenght of a pointer.
* @param	uintptr_t			The unsigned integer pointer to count lenght.
* @return	int					The lenght of characters of the pointer.
*/
int	ptr_len(uintptr_t num)
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
* @notice	This function converts a pointer.
* @param	uintptr_t			The unsigned integer pointer to print.
* @return	void				No return value needed now.
*/
void	put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

/**
* @notice	This function checks the pointer of something, converts it, prints
*			it and counts its pointer lenght.
* @param	unsigned_long_long	The unsigned integer pointer to print.
* @return	int					The lenght of characters of the printed
*								pointer.
*/
int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
	{
		put_ptr(ptr);
		len += ptr_len(ptr);
	}
	return (len);
}
