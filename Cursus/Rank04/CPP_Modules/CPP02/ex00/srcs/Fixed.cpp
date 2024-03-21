/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:54:19 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/23 17:07:38 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->_raw_value = fixed.getRawBits();
}

void	Fixed::swap(Fixed &first, Fixed &second) {
	std::swap(first._raw_value, second._raw_value);
}

Fixed	&Fixed::operator=(Fixed fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	swap(*this, fixed);
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw_value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw_value = raw;
}