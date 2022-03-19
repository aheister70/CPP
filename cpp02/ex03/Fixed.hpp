/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 15:11:36 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/13 15:11:36 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP02_FIXED_H
#define CPP02_FIXED_H

#include <iostream>

class Fixed {
private:
	int					_FixedPoint;
	static int const	_FractBits = 8;

public:
	Fixed(void);
	Fixed(int const input_i);
	Fixed(float const input_f);
	Fixed(Fixed const & src);
	Fixed& operator=(Fixed const & rhs);
	~Fixed(void);

	bool 	operator>(Fixed const & rhs) const;
	bool 	operator<(Fixed const & rhs) const;
	bool 	operator>=(Fixed const & rhs) const;
	bool 	operator<=(Fixed const & rhs) const;
	bool 	operator==(Fixed const & rhs) const;
	bool 	operator!=(Fixed const & rhs) const;

	Fixed 	operator*(Fixed const & rhs) const;
	Fixed 	operator/(Fixed const & rhs) const;
	Fixed 	operator+(Fixed const & rhs) const;
	Fixed 	operator-(Fixed const & rhs) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed&		max(Fixed & a, Fixed & b);
	static Fixed&		min(Fixed & a, Fixed & b);
	static const Fixed&	max(Fixed const & a, Fixed const & b);
	static const Fixed&	min(Fixed const & a, Fixed const & b);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int 	toInt(void) const;
};

std::ostream & operator<<(std::ostream & value, Fixed const & i);

#endif //CPP02_FIXED_H
