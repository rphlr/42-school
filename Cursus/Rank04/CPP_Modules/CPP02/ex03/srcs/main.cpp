/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:30 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/21 17:12:13 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void) {
	// Triangle a, b, c
	Point a = Point(0, 0);
	Point b = Point(0, 2);
	Point c = Point(2, 0);
	// Inside, on and outside of the hypotenuse
	Point p1 = Point(0.99f, 0.99f);
	Point p2 = Point(1, 1);
	Point p3 = Point(1.01f, 1.01f);
	// Inside, on and outside of the x cathether
	Point p4 = Point(0.01f, 0.5f);
	Point p5 = Point(0, 0.5f);
	Point p6 = Point(-0.01f, 0.5f);
	// Inside, on and outside of the y cathether
	Point p7 = Point(0.5f, 0.01f);
	Point p8 = Point(0.5f, 0);
	Point p9 = Point(0.5f, -0.01f);

	std::cout << "p1: " << std::boolalpha << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2: " << std::boolalpha << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3: " << std::boolalpha << bsp(a, b, c, p3) << std::endl;
	std::cout << "p4: " << std::boolalpha << bsp(a, b, c, p4) << std::endl;
	std::cout << "p5: " << std::boolalpha << bsp(a, b, c, p5) << std::endl;
	std::cout << "p6: " << std::boolalpha << bsp(a, b, c, p6) << std::endl;
	std::cout << "p7: " << std::boolalpha << bsp(a, b, c, p7) << std::endl;
	std::cout << "p8: " << std::boolalpha << bsp(a, b, c, p8) << std::endl;
	std::cout << "p9: " << std::boolalpha << bsp(a, b, c, p9) << std::endl;
}
