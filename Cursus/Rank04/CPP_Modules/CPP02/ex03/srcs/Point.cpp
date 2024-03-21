/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:36 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/21 17:12:04 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(Fixed(0)) , y(Fixed(0)) {}

Point::Point(const float x, const float y) : x(Fixed(x)) , y(Fixed(y)) {}

Point::Point(const Fixed x, const Fixed y) : x(x) , y(y) {}

Point::Point(const Point &point) : x(point.get_x()) , y(point.get_y()) {}

Point::~Point() {}

Point	&Point::operator=(const Point &point) {
	this->~Point();
	new (this) Point(point.get_x().toFloat(), point.get_y().toFloat());
	return *this;
}

Fixed	Point::get_x() const {
	return this->x;
}

Fixed	Point::get_y() const {
	return this->y;
}

