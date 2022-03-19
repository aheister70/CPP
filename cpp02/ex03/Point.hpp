/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 15:11:56 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/13 15:11:56 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP02_POINT_H
#define CPP02_POINT_H

#include "Fixed.hpp"

class Point {
private:
	Fixed _xFixed;
	Fixed _yFixed;

public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const & src);
	Point& operator=(Point const & rhs);
	~Point(void);

	Point 	operator-(Point const & rhs) const;

	Fixed const get_xFixed() const;
	Fixed const get_yFixed() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif //CPP02_POINT_H
