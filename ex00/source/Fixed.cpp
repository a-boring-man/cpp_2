/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/09/19 15:04:56 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _RawBits(0) {

	cout << "Default constructor called" << endl;
	return;
}

Fixed::Fixed( const Fixed & src ) : _RawBits(src._RawBits) {

	cout << "Copy constructor called" << endl;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {

	cout << "Destructor called" << endl;
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	cout << "Copy assignment operator called" << endl;
	if ( this != &rhs )
	{
		this->_RawBits = rhs.getRawBits();
	}
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits( void ) const {

	cout << "getRawBits member function called" << endl;
	return (this->_RawBits);
}

void	Fixed::setRawBits( int const raw ) {

	cout << "setRawBits member function called" << endl;
	this->_RawBits = raw;
	return;
}

/* ************************************************************************** */