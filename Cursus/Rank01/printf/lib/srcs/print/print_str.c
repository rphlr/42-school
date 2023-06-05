/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:44:11 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 14:46:04 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function prints a string.
* @param	char_pointer		The string to print.
* @return	int					The lenght of characters of the printed
*								string.
*/
int	print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[len])
		ft_putchar_fd(str[len++], 1);
	return (len);
}
