/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:55:46 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/22 13:50:40 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw_value(0) {}

Fixed::Fixed(const int i) {
	this->_raw_value = i << _fractional_bits;
}

Fixed::Fixed(const float f) {
	this->_raw_value = roundf(f * (1 << this->_fractional_bits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed) {
	this->_raw_value = fixed.getRawBits();
}

void	Fixed::swap(Fixed &first, Fixed &second) {
	std::swap(first._raw_value, second._raw_value);
}

Fixed	&Fixed::operator=(Fixed fixed) {
	Fixed::swap(*this, fixed);
	return *this;
}

Fixed	&Fixed::operator++() {
	this->_raw_value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--() {
	this->_raw_value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed	Fixed::operator+=(const Fixed &rhs) {
	this->_raw_value = this->_raw_value + rhs._raw_value;
	return *this;
}

Fixed	Fixed::operator-=(const Fixed &rhs) {
	this->_raw_value = this->_raw_value - rhs._raw_value;
	return *this;
}

Fixed	Fixed::operator*=(const Fixed &rhs) {
	this->_raw_value = ((long long)this->_raw_value
		* (long long)rhs.getRawBits()) >> this->_fractional_bits;
	return *this;
}

Fixed	Fixed::operator/=(const Fixed &rhs) {
	this->_raw_value = ((long long)this->_raw_value
		<< this->_fractional_bits) / rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	return this->_raw_value;
}

void	Fixed::setRawBits(int const raw) {
	this->_raw_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float)this->_raw_value / (1 << this->_fractional_bits);
}

int	Fixed::toInt(void) const {
	return this->_raw_value >> this->_fractional_bits;
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2) {
	return f1 < f2 ? f1 : f2;
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2) {
	return f1 < f2 ? f1 : f2;
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2) {
	return f1 > f2 ? f1 : f2;
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2) {
	return f1 > f2 ? f1 : f2;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool	operator==(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() == rhs.getRawBits() ? true : false;
}

bool operator!=(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() != rhs.getRawBits() ? true : false;
}

bool	operator<(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() < rhs.getRawBits() ? true : false;
}

bool	operator>(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() > rhs.getRawBits() ? true : false;
}

bool	operator<=(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() <= rhs.getRawBits() ? true : false;
}

bool	operator>=(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() >= rhs.getRawBits() ? true : false;
}

Fixed	operator+(Fixed lhs, const Fixed &rhs) {
	lhs += rhs;
	return lhs;
}

Fixed	operator-(Fixed lhs, const Fixed &rhs) {
	lhs -= rhs;
	return lhs;
}

Fixed	operator*(Fixed lhs, const Fixed &rhs) {
	lhs *= rhs;
	return lhs;
}

Fixed	operator/(Fixed lhs, const Fixed &rhs) {
	lhs /= rhs;
	return lhs;
}