/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:55:01 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/22 13:50:40 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_raw_value = i << _fractional_bits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_raw_value = roundf(f * (1 << this->_fractional_bits));
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
	Fixed::swap(*this, fixed);
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw_value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float)this->_raw_value / (1 << this->_fractional_bits);
}

int	Fixed::toInt(void) const {
	return this->_raw_value >> this->_fractional_bits;
}