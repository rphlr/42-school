/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:19 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/22 13:50:40 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class	Fixed {
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed	&operator=(Fixed fixed);

		void	swap(Fixed &first, Fixed &second);

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		Fixed	operator+=(const Fixed &rhs);
		Fixed	operator-=(const Fixed &rhs);
		Fixed	operator*=(const Fixed &rhs);
		Fixed	operator/=(const Fixed &rhs);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed		&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
	private:
		int					_raw_value;
		static const int	_fractional_bits = 8;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

bool	operator==(const Fixed &lhs, const Fixed &rhs);
bool	operator!=(const Fixed &lhs, const Fixed &rhs);
bool	operator<(const Fixed &lhs, const Fixed &rhs);
bool	operator>(const Fixed &lhs, const Fixed &rhs);
bool	operator<=(const Fixed &lhs, const Fixed &rhs);
bool	operator>=(const Fixed &lhs, const Fixed &rhs);

Fixed	operator+(Fixed lhs, const Fixed &rhs);
Fixed	operator-(Fixed lhs, const Fixed &rhs);
Fixed	operator*(Fixed lhs, const Fixed &rhs);
Fixed	operator/(Fixed lhs, const Fixed &rhs);

#endif