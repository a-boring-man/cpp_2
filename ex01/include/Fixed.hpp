/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:26:36 by jrinna            #+#    #+#             */
/*   Updated: 2022/09/20 08:21:42 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed( const int i );
		Fixed( const float f );
		~Fixed();

		Fixed &	operator=( Fixed const & rhs );
	
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