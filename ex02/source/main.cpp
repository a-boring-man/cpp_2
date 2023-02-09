/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:31:02 by jrinna            #+#    #+#             */
/*   Updated: 2023/02/09 12:54:46 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed d(508);
	Fixed c(2.5f);
	
	cout << "ADDTITION" << endl;
	std::cout << d + c << std::endl;
	cout << "soustraction" << endl;
	std::cout << d - c << std::endl;
	cout << "multiplication" << endl;
	std::cout << d * c << std::endl;
	cout << "division" << endl;
	std::cout << d / c << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}