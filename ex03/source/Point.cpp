/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:18:36 by jrinna            #+#    #+#             */
/*   Updated: 2022/09/20 11:04:13 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// Default constructor :
Point::Point() : _x(0), _y(0) {

	cout << "Point default constructor called" << endl;
	return;
}

// Double const float initialisation constructor :
Point::Point( const float x, const float y ) : _x(x), _y(y) {

	cout << "Point double const float initialisation constructor called" << endl;
	return;
}

// Copy constructor :
Point::Point( const Point & src ) : _x(src._x), _y(src._y) {

	cout << "Point copy constructor called" << endl;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point() {

	cout << "Point destructor called" << endl;
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	cout << "Point assignment operator called" << endl;
	if ( this != &rhs )
	{
		this->set_x(rhs.get_x());
		this->set_y(rhs.get_y());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & P )
{
	o << "(" << P.get_x() << ", " << P.get_y() << ")";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

// Getter _x :
const Fixed	Point::get_x( void ) const {

	cout << "Point get_x called" << endl;
	return(this->_x);
}

// Getter _y :
const Fixed	Point::get_y( void ) const {

	cout << "Point get_y called" << endl;
	return(this->_y);
}

// Setter _x :
void	Point::set_x( const Fixed x ) {

	cout << "Point set_x called" << endl;

	Fixed	*ptr = (Fixed *)&this->_x;
	*ptr = x;

	return;
}

// Setter _y :
void	Point::set_y( const Fixed y ) {

	cout << "Point set_y called" << endl;

	Fixed	*ptr = (Fixed *)&this->_y;
	*ptr = y;

	return;
}

/* ************************************************************************** */