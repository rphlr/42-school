/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:52:45 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/21 16:05:42 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class	Point {
	public:
		Point();
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point &point);
		~Point();

		Point	&operator=(const Point &point);
		Fixed	get_x() const;
		Fixed	get_y() const;
	private:
		const Fixed	x;
		const Fixed	y;
};

#endif