/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:17:40 by jrinna            #+#    #+#             */
/*   Updated: 2022/09/20 11:02:00 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point( const float x, const float y );
		Point( Point const & src );
		~Point();

		Point &		operator=( Point const & rhs );

		const Fixed	get_x( void ) const;
		const Fixed	get_y( void ) const;
		void		set_x( const Fixed x );
		void		set_y( const Fixed y );

	private:

		const Fixed	_x;
		const Fixed _y;

};

std::ostream &			operator<<( std::ostream & o, Point const & P );
