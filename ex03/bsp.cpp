/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:54:16 by fcoullou          #+#    #+#             */
/*   Updated: 2024/11/28 15:51:23 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// Retourne le produit vectoriel de deux vecteurs en 2D.
// Utilisé pour déterminer l'orientation relative des vecteurs.
//
//	Formules :
// r = ref,	i = inconnue, o = other
// bool = riX	* roY	- riY	* roX
Fixed	crossProduct(Fixed riX, Fixed roY, Fixed riY, Fixed roX)
{
	return (riX * roY) - (riY * roX);
}

//	Verifie si (c) et (point) sont du meme cote de (ab)
// Si (c) et (point) ont le meme signe, ils sont du meme cote de (ab)
//
//	Formules :
//	Pour (a) en ref, et (c) et (point) a determiner du cote de (ab)
// bool = (cx - ax)	* (by - ay)	- (cy - ay)	* (bx - ax)
// bool = acX		* abY		-		acY	* abX
bool isSameSide(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abX( a.diff( b.getXValue(), a.getXValue() ) );
    Fixed abY( a.diff( b.getYValue(), a.getYValue() ) );

    Fixed acX( a.diff( c.getXValue(), a.getXValue() ) );
    Fixed acY( a.diff( c.getYValue(), a.getYValue() ) );
	
    Fixed apX( a.diff( point.getXValue(), a.getXValue() ) );
    Fixed apY( a.diff( point.getYValue(), a.getYValue() ) );

    bool cSide( crossProduct(acX, abY, acY, abX) >= 0 );
    bool pSide( crossProduct(apX, abY, apY, abX) >= 0 );

    return cSide == pSide;
}

//	Binary Space Partitioning :
// Retourne "true" si le (point) est a l'interieur du triangle (abc)
// Si (point) est du meme cote que le sommet opposes aux droites (ab) (bc) et (ac),
// il se trouve donc dans le triangle.
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return	isSameSide(a, b, c, point) &&
			isSameSide(b, c, a, point) &&
			isSameSide(c, a, b, point);
}
