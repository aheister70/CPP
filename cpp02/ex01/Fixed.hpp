/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 15:07:45 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/13 15:07:45 by annaheister   ########   odam.nl         */
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

	int		getRawBits(void) const;
	void	setRawBits(int const value);
	float	toFloat(void) const;
	int 	toInt(void) const;
};

std::ostream & operator<<(std::ostream & value, Fixed const & i);

#endif //CPP02_FIXED_H
