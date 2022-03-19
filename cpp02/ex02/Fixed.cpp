/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 15:08:42 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/13 15:08:42 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _FixedPoint(0)
{
	return;
}

Fixed::Fixed(int const input_i)
{
	setRawBits(input_i << this->_FractBits);
	return;
}

Fixed::Fixed(float const input_f)
{
	float int_fract;

	int_fract = input_f * (1 << this->_FractBits);
	setRawBits((int)roundf(int_fract));
	return;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	return;
}

bool Fixed::operator>(Fixed const & rhs) const
{
	if (this->_FixedPoint > rhs._FixedPoint)
		return true;
	return false;
}

bool Fixed::operator<(Fixed const & rhs) const
{
	if (this->_FixedPoint < rhs._FixedPoint)
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	if (this->_FixedPoint >= rhs._FixedPoint)
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	if (this->_FixedPoint <= rhs._FixedPoint)
		return true;
	return false;
}

bool Fixed::operator==(Fixed const & rhs) const
{
	if (this->_FixedPoint == rhs._FixedPoint)
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	if (this->_FixedPoint != rhs._FixedPoint)
		return true;
	return false;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_FixedPoint = rhs._FixedPoint;
	return *this;
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	Fixed New;

	New.setRawBits(this->_FixedPoint * rhs._FixedPoint >> this->_FractBits);
	return New;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed New;

	New.setRawBits((this->_FixedPoint << this->_FractBits) / rhs._FixedPoint);
	return New;
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	Fixed New;

	New.setRawBits(this->_FixedPoint + rhs._FixedPoint);
	return New;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	Fixed New;

	New.setRawBits(this->_FixedPoint - rhs._FixedPoint);
	return New;
}

/*
 *   The parameter of overloaded pre-increment operator must have type 'void'.
 */

Fixed& Fixed::operator++(void)
{
	++this->_FixedPoint;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	--this->_FixedPoint;
	return *this;
}

/*
 *   For the post-increment function you store "this" fixed point value
 *   in a temporary instance. Then you increment "this" value and return
 *   the (unchanged) tmp. The parameter of overloaded post-increment operator
 *   must have type 'int'.
 */

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->_FixedPoint);
	this->_FixedPoint++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->_FixedPoint);
	this->_FixedPoint--;
	return tmp;
}

int Fixed::getRawBits(void) const
{
	return this->_FixedPoint;
}

void Fixed::setRawBits(int const value)
{
	this->_FixedPoint = value;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_FixedPoint / (float)(1 << this->_FractBits));
}

int 	Fixed::toInt(void) const
{
	return ((int)this->_FixedPoint >> this->_FractBits);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	return b;
}

std::ostream & operator<<(std::ostream & out, Fixed const & input)
{
	out << input.toFloat();
	return out;
}
