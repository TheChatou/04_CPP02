/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:09 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/28 13:29:39 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::_fract = 8;

Fixed::Fixed(): _fixedValue(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
	{
		_fixedValue = fixed._fixedValue;
	}
	return *this;
}

//	OPERATEURS DE COMPARAISON //////////////////////////////////////////////////
bool Fixed::operator>(const Fixed& fixed) const
{
	return this->_fixedValue > fixed._fixedValue;
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return this->_fixedValue < fixed._fixedValue;
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return this->_fixedValue >= fixed._fixedValue;
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return this->_fixedValue <= fixed._fixedValue;
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return this->_fixedValue == fixed._fixedValue;
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return this->_fixedValue != fixed._fixedValue;
}

//	OPERATEURS ARITHMETIQUES ///////////////////////////////////////////////////
Fixed Fixed::operator+(const Fixed& fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

//	OPERATEURS D'INCREMENTATION ////////////////////////////////////////////////
//  Pre-incrementation : ++a, Incremente la valeur de l'objet avant de retourner l'objet.
Fixed& Fixed::operator++(void)
{
	this->_fixedValue += 1;
	return *this;
}

//  Post-incrementation : a++, Retourne la valeur de l'objet avant de l'incrementer.
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedValue += 1;
	return tmp;
}

//	Pre-decrementation : --a, Decremente la valeur de l'objet avant de retourner l'objet.
Fixed& Fixed::operator--(void)
{
	this->_fixedValue -= 1;
	return *this;
}

//	Post-decrementation : a--, Retourne la valeur de l'objet avant de le decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedValue -= 1;
	return tmp;
}

//	CONSTRUCTEURS //////////////////////////////////////////////////////////////
Fixed::Fixed(int const nb) : _fixedValue(nb << _fract) {}

Fixed::Fixed(float const fl) : _fixedValue(roundf(fl * (1 << _fract))) {}

int		Fixed::getRawBits(void) const
{
	return _fixedValue;
}

void	Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

//	1 << _fract = 256 quand _fract = 8. Donc pour retourner le float, on divise par 256. 
// ex: _fixedValue = 2080. (2080 / 256) = 8.125.
// 256 / 256 = 1. 512 / 256 = 2. 128 / 256 = 0.5
float	Fixed::toFloat( void ) const
{
	return  static_cast<float>(this->_fixedValue) / (1 << _fract);
}

//	>> _fract = 256 quand _fract = 8. Donc pour retourner le int, on divise par 256.
// ex: _fixedValue = 509. 509 / 256 = 1.
// 1024 / 256 = 4. 128 / 256 = 0.5
int		Fixed::toInt( void ) const
{
	return this->_fixedValue >> _fract;
}

//	MIN & MAX	////////////////////////////////////////////////////////////////
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}
const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

//	OUTSIDE ///////////////////////////////////////////////////////////////////
std::ostream&	operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
