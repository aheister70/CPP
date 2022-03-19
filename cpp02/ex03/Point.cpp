/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 15:11:47 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/13 15:11:47 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _xFixed(0), _yFixed(0)
{
	return;
}

Point::Point(float const input_x, float const input_y) : _xFixed(input_x), _yFixed(input_y)
{
	return;
}

Point::Point(Point const & src)
{
	*this = src;
	return;
}

Point& Point::operator=(Point const & rhs)
{
	if (this != &rhs)
	{
		this->_xFixed = rhs._xFixed;
		this->_yFixed = rhs._yFixed;
	}
	return *this;
}

Point::~Point(void)
{
	return;
}

Point 	Point::operator-(Point const & rhs) const
{
	Point New;

	New._xFixed = this->_xFixed - rhs._xFixed;
	New._yFixed = this->_yFixed - rhs._yFixed;
	return (New);
}

Fixed const Point::get_xFixed() const
{
	return this->_xFixed;
}

Fixed const Point::get_yFixed() const
{
	return this->_yFixed;
}

