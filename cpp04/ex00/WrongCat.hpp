/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 10:24:29 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 10:24:29 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_WRONGCAT_H
#define CPP04_WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(WrongCat const & src);
	WrongCat& operator=(WrongCat const & rhs);
	virtual ~WrongCat(void);

	void	makeSound(void) const;
};

#endif //CPP04_WRONGCAT_H
