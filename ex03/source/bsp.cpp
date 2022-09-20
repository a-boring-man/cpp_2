/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:05:01 by jrinna            #+#    #+#             */
/*   Updated: 2022/09/20 13:05:12 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	ft_area( const Point p1, const Point p2, const Point p3 ) {

	return ( abs ((p1.get_x() * (p2.get_y() - p3.get_y()) + p2.get_x() * (p3.get_y() - p1.get_y()) + p3.get_x() * (p1.get_y() - p2.get_y())) * 0.5 );
}

bool	ft_is_inside( const Point T1, const Point T2, const Point T3, const Point p) {

	float	A = ft_area( T1, T2, T3 );
	float	A1 = ft_area( T1, T2, p );
	float	A2 = ft_area( p, T2, T3 );
	float	A3 = ft_area( T1, p, T3 );
}
