/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:59 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 14:57:40 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @author	rrouille
* @title	Printf
* @notice	This project is clear and efficient. You have to recode printf. You
*			will then be able to reuse it in your future projects. This project
*			is mainly about variable size arguments.
*/

#include "ft_printf.h"

/**
* @notice	This function links and converts the character next to '%' to the
*			correct argument and function.
* @param	va_list				The arguments.
* @param	const_char			The character next to '%'.
* @return	int					The lenght of characters of the printed
*								conversion.
*/
int	arg_conversion(va_list args, const char conversion)
{
	int	len;

	len = 1;
	if (conversion == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (conversion == 's')
		len = print_str(va_arg(args, char *));
	else if (conversion == 'p')
		len = print_ptr(va_arg(args, unsigned long long));
	else if (conversion == 'd' || conversion == 'i')
		len = print_nbr(va_arg(args, int));
	else if (conversion == 'u')
		len = print_unsigned(va_arg(args, unsigned int));
	else if (conversion == 'x' || conversion == 'X')
		len = print_hex(va_arg(args, unsigned int), conversion);
	else if (conversion == '%')
		ft_putstr_fd("%", 1);
	return (len);
}

/**
* @notice	The printf utility conversions and prints its arguments, after the
*			first, under control of the conversion. The conversion is a character
*			string which contains three types of objects: plain characters, which
*			are simply copied to standard output, character escape sequences
*			which are converted and copied to the standard output, and conversion
*			specifications, each of which causes printing of the next successive
*			argument.
* @param	const_char			The arguments are treated as strings
* @param	...					A variadic argument corresponding to each character
*								after the '%' if there is some.
* @return	int					The string lenght of all arguments.
*/
int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += arg_conversion(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
