/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:35:10 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/11 10:35:10 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed sign(Point point, Point p1, Point p2)
{
	Fixed a;
	Fixed b;
	Fixed c;

	a = (point.get_xFixed() - p2.get_xFixed()) * (p1.get_yFixed() - p2.get_yFixed());
	b = (p1.get_xFixed() - p2.get_xFixed()) * (point.get_yFixed() - p2.get_yFixed());
	c = a - b;
	return c;
}

/*
 * The function bsp calculates the barycentric coordinates of point P.
 * The barycentric coordinates are related to the area of the (sub)triangles
 * that can be drawn into the triangle by using point P. If the areas are equal,
 * the barycentric coordinates are equal.
 * The function works for both clockwise order of vertices (negatives) and
 * counter clockwise order (positive). Important is that all values of the barycentric
 * coordinates of point p have the same sign and the value != 0.
 * Otherwise point P is lying outside of the triangle.
 */

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed check_1;
	Fixed check_2;
	Fixed check_3;

	check_1 = sign(point, a, b);
	check_2 = sign(point, b, c);
	check_3 = sign(point, c, a);

	if (check_1 < 0 && check_2 < 0 && check_3 < 0)
		return true;
	else if (check_1 > 0 && check_2 > 0 && check_3 > 0)
		return true;
	return false;
}
