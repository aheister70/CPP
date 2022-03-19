/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 15:07:37 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/13 15:07:37 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _FixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

/*
 *   To get the fixed point value you shift the integer 8 bits to the left
 *   (means multiplying it by 256)
 */

Fixed::Fixed(int const input_i)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(input_i << this->_FractBits);
	return;
}

/*
 *   It is not possible to directly shift a float 8 bits to the left (types don't match).
 *   An escape is to shift a "1" 8 bits to the left and multiply input_f with this result.
 *   Because this has to result into an int you round the value with the function roundf.
 *   and typecast it with (int).
 */

Fixed::Fixed(float const input_f)
{
	float int_fract;

	std::cout << "Float constructor called" << std::endl;
	int_fract = input_f * (1 << this->_FractBits);
	setRawBits((int)roundf(int_fract));
	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_FixedPoint = rhs._FixedPoint;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const
{
	return this->_FixedPoint;
}

void Fixed::setRawBits(int const value)
{
	this->_FixedPoint = value;
}

/*
 *   To get the original float value, you need to shift the fixed point value 8 bits to the right.
 *   Because of the type mismatch you can't directly do this. You first shift a "1" 8 bits to the left
 *   (it's not possible to shift an int "1" to the right because that will end in a 0).
 *   Then you divide you fixed point with this number (typecast to a float).
 */

float	Fixed::toFloat(void) const
{
	return (float)this->_FixedPoint / (float)(1 << this->_FractBits);
}

/*
 *   To get the original int value, you need to shift the fixed point value 8 bits to the right.
 */

int 	Fixed::toInt(void) const
{
	return (int)this->_FixedPoint >> this->_FractBits;
}

/*
 *   Overbooking the stream redirection to the stdout: the fixed point values
 *   are converted to floats.
 */

std::ostream & operator<<(std::ostream & out, Fixed const & input)
{
	out << input.toFloat();
	return out;
}
