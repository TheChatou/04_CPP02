/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:22:47 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/28 14:06:01 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();
		Point(const Point &point);
		~Point();
		Point &operator=(const Point &point);
		
		Point(float const x, float const y);
		
		Fixed	getXValue( void ) const;
		Fixed	getYValue( void ) const;

		Fixed	fixedMinusFixed(Fixed x, Fixed y) const; 
		Fixed	diff(const Fixed one, const Fixed two) const;
};

#endif