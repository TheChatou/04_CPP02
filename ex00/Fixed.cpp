/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:09 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/12 17:00:19 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0), _fractionalBits(8) {}

Fixed::Fixed(const Fixed &fixed): _fixedPointValue(fixed._fixedPointValue), _fractionalBits(fixed._fractionalBits) {}

~Fixed::Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed &operator=(const Fixed &fixed)
{
	if (!this != &fixed)
	{
		_fixedPointValue = fixed._fixedPointValue;
		_fractionalBits = fixed._fractionalBits;
	}
	return *this;
}
