/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:47:53 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/28 15:37:11 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(1.0, 1.0);
	Point	b(3.0, 6.0);
	Point	c(5.0, 3.0);
	
	Point	one(2, 2);
	Point	two(2, 3.504);
	Point	three(1, 1);
	Point	four(4.5, 2.5);

	std::string result;
	
	std::cout	<< std::endl << "The Triangle coordinates are : a("
				<< a.getXValue() << ", " << a.getYValue()
				<< "), b(" << b.getXValue() << ", " << b.getYValue()
				<< "), c(" << c.getXValue() << ", " << c.getYValue()
				<< ")" << std::endl << std::endl;
				
	if (bsp(a, b, c, one))
		result = "inside";
	else
		result = "outside";
	std::cout	<< "the point one (" << one.getXValue() << ", " << one.getYValue()
				<< ") is : " << result << std::endl;
	
	if (bsp(a, b, c, two))
		result = "inside";
	else
		result = "outside";
	std::cout	<< "the point two (" << two.getXValue() << ", " << two.getYValue()
				<< ") is : " << result << std::endl;
	
	if (bsp(a, b, c, three))
		result = "inside";
	else
		result = "outside";
	std::cout	<< "the point three (" << three.getXValue() << ", " << three.getYValue()
				<< ") is : " << result << std::endl;
	
	if (bsp(a, b, c, four))
		result = "inside";
	else
		result = "outside";
	std::cout	<< "the point four (" << four.getXValue() << ", " << four.getYValue()
				<< ") is : " << result << std::endl << std::endl;
	
	return 0;
}
