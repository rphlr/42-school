/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:04 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/21 17:07:14 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

int	main(void) {
	std::cout << "--- subject pdf test start ---" << std::endl;
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "--- subject pdf test end ---" << std::endl << std::endl;

	std::cout << "--- custom tests ---" << std::endl;
	Fixed	c = Fixed(4.5f);
	Fixed	d = Fixed(1.5f);

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c + d = " << c + d << std::endl << std::endl;

	Fixed	e = Fixed(4.5f);

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "c < d ? " << std::boolalpha << (c < d) << std::endl;
	std::cout << "c > d ? " << std::boolalpha << (c > d) << std::endl;
	std::cout << "c <= d ? " << std::boolalpha << (c <= d) << std::endl;
	std::cout << "c >= d ? " << std::boolalpha << (c >= d) << std::endl;
	std::cout << "c <= e ? " << std::boolalpha << (c <= e) << std::endl;
	std::cout << "c >= e ? " << std::boolalpha << (c >= e) << std::endl;
	std::cout << "c == d ? " << std::boolalpha << (c == d) << std::endl;
	std::cout << "c == e ? " << std::boolalpha << (c == e) << std::endl;
	std::cout << "c != d ? " << std::boolalpha << (c != d) << std::endl;
	std::cout << "c != e ? " << std::boolalpha << (c != e) << std::endl << std::endl;

	Fixed	f = Fixed(-21.25f);
	Fixed	g = Fixed(0);
	Fixed	h = Fixed(42.75f);

	std::cout << "f = " << f << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "h = " << h << std::endl;
	std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;
	std::cout << "max(g, h): " << Fixed::max(g, h) << std::endl;
	std::cout << "max(f, h): " << Fixed::max(f, h) << std::endl;
	std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
	std::cout << "min(g, h): " << Fixed::min(g, h) << std::endl;
	std::cout << "min(f, h): " << Fixed::min(f, h) << std::endl;
	return 0;
}
