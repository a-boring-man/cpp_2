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

// Default constructor :
Fixed::Fixed() : _RawBits(0) {

	cout << "Default constructor called" << endl;
	return;
}

// Copy constructor :
Fixed::Fixed( const Fixed & src ) : _RawBits(src._RawBits) {

	cout << "Copy constructor called" << endl;
	return;
}

// From Int type constructor :
Fixed::Fixed( const int i ) : _RawBits(i << this->_fractional_bits) {

	cout << "Int constructor called" << endl;
	return;
}

// From Float type constructor :
Fixed::Fixed( const float f ) {

	this->_RawBits = roundf(f * (1 << this->_fractional_bits));
	cout << "Float constructor called" << endl;
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

std::ostream &			operator<<( std::ostream & o, Fixed const & F )
{
	o << F.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int		Fixed::toInt( void ) const {

	return (this->_RawBits >> this->_fractional_bits);
}

float	Fixed::toFloat( void ) const {

	return ((float)this->_RawBits / (float)(1 << this->_fractional_bits));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits( void ) const {

	//cout << "getRawBits member function called" << endl;
	return (this->_RawBits);
}

void	Fixed::setRawBits( int const raw ) {

	//cout << "setRawBits member function called" << endl;
	this->_RawBits = raw;
	return;
}

/* ************************************************************************** */