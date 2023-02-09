/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:03 by jrinna            #+#    #+#             */
/*   Updated: 2023/02/09 12:58:40 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

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

// Operator = :
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
** ------------------------------ <,>,<=,>=,==,!= -----------------------------
*/

// Operator > :
bool	Fixed::operator>( Fixed const & rhs ) const {

	cout << "Operator : > called" << endl;
	return (this->_RawBits > rhs._RawBits);
}

// Operator < :
bool	Fixed::operator<( Fixed const & rhs ) const {

	cout << "Operator : < called" << endl;
	return (this->_RawBits < rhs._RawBits);
}

// Operator >= :
bool	Fixed::operator>=( Fixed const & rhs ) const {

	cout << "Operator : >= called" << endl;
	return (this->_RawBits >= rhs._RawBits);
}

// Operator <= :
bool	Fixed::operator<=( Fixed const & rhs ) const {

	cout << "Operator : <= called" << endl;
	return (this->_RawBits <= rhs._RawBits);
}

// Operator == :
bool	Fixed::operator==( Fixed const & rhs ) const {

	cout << "Operator : == called" << endl;
	return (this->_RawBits == rhs._RawBits);
}

// Operator != :
bool	Fixed::operator!=( Fixed const & rhs ) const {

	cout << "Operator : != called" << endl;
	return (this->_RawBits != rhs._RawBits);
}

/*
** ---------------------------------- +,-,*,/ ---------------------------------
*/

// Operator + :
Fixed	Fixed::operator+( Fixed const & rhs) const {

	cout << "Operator : + called" << endl;
	Fixed	result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

// Operator - :
Fixed	Fixed::operator-( Fixed const & rhs) const {

	cout << "Operator : - called" << endl;
	Fixed	result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

// Operator * :
Fixed	Fixed::operator*( Fixed const & rhs) const {

	cout << "Operator : * called" << endl;
	Fixed	result;
	result.setRawBits((this->toInt() * rhs.getRawBits()));
	return (result);
}

// Operator / fast avec precision mais perte de range
Fixed	Fixed::operator/( Fixed const & rhs) const {

	cout << "Operator : / called" << endl;
	Fixed	result;
	result.setRawBits((this->getRawBits() * (1 << this->_fractional_bits)) / rhs.getRawBits());
	return (result);
}
// Operator / fast sans precision mais sans perte de range
/* Fixed	Fixed::operator/( Fixed const & rhs) const {

	cout << "Operator : / called" << endl;
	Fixed	result = Fixed((this->getRawBits() / rhs.getRawBits()));
	return (result);
} */
// Operator / slow avec precision sans perte de range
/* Fixed	Fixed::operator/( Fixed const & rhs) const {

	cout << "Operator : / called" << endl;
	Fixed	result = Fixed(this->toFloat() / rhs.toFloat());
	return (result);
} */

/*
** ----------------------------- n++,++n,n--,--n ------------------------------
*/

// Operator ++n :
Fixed & Fixed::operator++( void ) {

	cout << "Operator : ++n called" << endl;
	this->_RawBits++;
	return (*this);
}

// Operator n++ :
Fixed	Fixed::operator++( int ) {

	cout << "Operator : n++ called" << endl;
	Fixed	temp( *this );
	this->_RawBits++;
	return (temp);
}

// Operator --n :
Fixed & Fixed::operator--( void ) {

	cout << "Operator : --n called" << endl;
	this->_RawBits--;
	return (*this);
}

// Operator n-- :
Fixed	Fixed::operator--( int ) {

	cout << "Operator : n-- called" << endl;
	Fixed	temp( *this );
	this->_RawBits--;
	return (temp);
}

/*
** -------------------------------- REDIRECTION -------------------------------
*/

// Ostream redirection :
std::ostream &			operator<<( std::ostream & o, Fixed const & F )
{
	o << std::setprecision(10) << F.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const Fixed	&Fixed::max( const Fixed & a, const Fixed & b ) {


	cout << "const Max function called" << endl;
	if ( a._RawBits >= b._RawBits )
		return (a);
	return (b);
}

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