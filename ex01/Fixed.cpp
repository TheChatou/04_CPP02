/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:09 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/25 16:58:05 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::_fract = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &fixed)
	{
		_value = fixed._value;
	}
	return *this;
}

Fixed::Fixed(int const nb) : _value(nb << _fract)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const fl) : _value(roundf(fl * (1 << _fract)))
{
	std::cout << "Float constructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return  static_cast<float>(this->_value) / (1 << _fract);
}

int		Fixed::toInt( void ) const
{
	return this->_value >> _fract;
}

//	OUTSIDE //////////////////////////////////////////////////////////////////////
std::ostream&	operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
