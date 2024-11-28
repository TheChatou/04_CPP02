/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:22:14 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/28 14:21:40 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Point &point): _x(point._x), _y(point._y) {}

Point::~Point() {}

Point& Point::operator=(const Point &point)
{
	(void) point;
	return *this;
}

Point::Point(float const x, float const y): _x(x), _y(y) {}

Fixed	Point::getXValue( void ) const
{
	return _x;
}

Fixed	Point::getYValue( void ) const
{
	return _y;
}

//	Retourne : one - two
Fixed	Point::diff(const Fixed one, const Fixed two) const
{
	return one.getRawBits() - two.getRawBits();
}
