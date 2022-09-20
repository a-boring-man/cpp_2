/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/09/20 09:32:28 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// Default constructor :
Fixed::Fixed() : _RawBits(0) {

	cout << "Fixed default constructor called" << endl;
	return;
}

// Copy constructor :
Fixed::Fixed( const Fixed & src ) : _RawBits(src._RawBits) {

	cout << "Fixed copy constructor called" << endl;
	return;
}

// From Int type constructor :
Fixed::Fixed( const int i ) : _RawBits(i << this->_fractional_bits) {

	cout << "Fixed int constructor called" << endl;
	return;
}

// From Float type constructor :
Fixed::Fixed( const float f ) {

	this->_RawBits = roundf(f * (1 << this->_fractional_bits));
	cout << "Fixed float constructor called" << endl;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {

	cout << "Fixed destructor called" << endl;
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Operator = :
Fixed &	Fixed::operator=( Fixed const & rhs )
{
	cout << "Fixed copy assignment operator called" << endl;
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

	cout << "Fixed operator : > called" << endl;
	return (this->_RawBits > rhs._RawBits);
}

// Operator < :
bool	Fixed::operator<( Fixed const & rhs ) const {

	cout << "Fixed operator : < called" << endl;
	return (this->_RawBits < rhs._RawBits);
}

// Operator >= :
bool	Fixed::operator>=( Fixed const & rhs ) const {

	cout << "Fixed operator : >= called" << endl;
	return (this->_RawBits >= rhs._RawBits);
}

// Operator <= :
bool	Fixed::operator<=( Fixed const & rhs ) const {

	cout << "Fixed operator : <= called" << endl;
	return (this->_RawBits <= rhs._RawBits);
}

// Operator == :
bool	Fixed::operator==( Fixed const & rhs ) const {

	cout << "Fixed operator : == called" << endl;
	return (this->_RawBits == rhs._RawBits);
}

// Operator != :
bool	Fixed::operator!=( Fixed const & rhs ) const {

	cout << "Fixed operator : != called" << endl;
	return (this->_RawBits != rhs._RawBits);
}

/*
** ---------------------------------- +,-,*,/ ---------------------------------
*/

// Operator + :
Fixed	Fixed::operator+( Fixed const & rhs) const {

	cout << "Fixed operator : + called" << endl;
	float	result = this->toFloat() + rhs.toFloat();
	return ( Fixed(result) );
}

// Operator - :
Fixed	Fixed::operator-( Fixed const & rhs) const {

	cout << "Fixed operator : - called" << endl;
	float	result = this->toFloat() - rhs.toFloat();
	return ( Fixed(result) );
}

// Operator * :
Fixed	Fixed::operator*( Fixed const & rhs) const {

	cout << "Fixed operator : * called" << endl;
	float	result = this->toFloat() * rhs.toFloat();
	return ( Fixed(result) );
}

// Operator / :
Fixed	Fixed::operator/( Fixed const & rhs) const {

	cout << "Fixed operator : / called" << endl;
	float	result = this->toFloat() / rhs.toFloat();
	return ( Fixed(result) );
}

/*
** ----------------------------- n++,++n,n--,--n ------------------------------
*/

// Operator ++n :
Fixed & Fixed::operator++( void ) {

	cout << "Fixed operator : ++n called" << endl;
	this->_RawBits++;
	return (*this);
}

// Operator n++ :
Fixed	Fixed::operator++( int ) {

	cout << "Fixed operator : n++ called" << endl;
	Fixed	temp( *this );
	this->_RawBits++;
	return (temp);
}

// Operator --n :
Fixed & Fixed::operator--( void ) {

	cout << "Fixed operator : --n called" << endl;
	this->_RawBits--;
	return (*this);
}

// Operator n-- :
Fixed	Fixed::operator--( int ) {

	cout << "Fixed operator : n-- called" << endl;
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
	o << F.toFloat();
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

Fixed	&Fixed::max( Fixed & a, Fixed & b ) {


	cout << "Max function called" << endl;
	if ( a._RawBits >= b._RawBits )
		return (a);
	return (b);
}

const Fixed	&Fixed::min( const Fixed & a, const Fixed & b ) {


	cout << "const Min function called" << endl;
	if ( a._RawBits <= b._RawBits )
		return (a);
	return (b);
}

Fixed	&Fixed::min( Fixed & a, Fixed & b ) {


	cout << "Min function called" << endl;
	if ( a._RawBits <= b._RawBits )
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

	cout << "Fixed getRawBits member function called" << endl;
	return (this->_RawBits);
}

void	Fixed::setRawBits( int const raw ) {

	cout << "Fixed setRawBits member function called" << endl;
	this->_RawBits = raw;
	return;
}

/* ************************************************************************** */