/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:54:26 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/22 13:50:40 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class	Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed	&operator=(Fixed fixed);

		void	swap(Fixed &first, Fixed &second);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_raw_value;
		static const int	_fractional_bits = 8;
};

#endif