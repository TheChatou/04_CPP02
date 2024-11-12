/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:58 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/12 16:49:03 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};