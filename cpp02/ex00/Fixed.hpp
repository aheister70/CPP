/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 15:05:14 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/13 15:05:14 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP02_FIXED_H
#define CPP02_FIXED_H

class Fixed {
private:
	int					_FixedPoint;
	static int const	_FractBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed & operator=(Fixed const & rhs);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const value);
};

#endif //CPP02_FIXED_H
