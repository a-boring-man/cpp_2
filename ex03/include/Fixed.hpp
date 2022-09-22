/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:26:36 by jrinna            #+#    #+#             */
/*   Updated: 2022/09/22 08:54:19 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <cmath>
# include <math.h>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed( const int i );
		Fixed( const float f );
		~Fixed();

		Fixed &	operator=( Fixed const & rhs );
	
		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;

		Fixed	operator+( Fixed const & rhs ) const;
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		Fixed & operator++( void );
		Fixed	operator++( int );
		Fixed & operator--( void );
		Fixed	operator--( int );

		static Fixed & min( Fixed & a, Fixed & b);
		static const Fixed & min( const Fixed & a, const Fixed & b);
		static Fixed & max( Fixed & a, Fixed & b);
		static const Fixed & max( const Fixed & a, const Fixed & b);
	
		float	toFloat( void ) const;
		int		toInt( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);

	private:

		int					_RawBits;
		static const int	_fractional_bits = 8;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & F );

using std::cout;
using std::endl;
using std::string;