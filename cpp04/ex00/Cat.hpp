/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/20 13:08:24 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/20 13:08:24 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_CAT_H
#define CPP04_CAT_H

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(Cat const & src);
	Cat& operator=(Cat const & rhs);
	virtual ~Cat(void);

	void	makeSound(void) const;
};

#endif //CPP04_CAT_H
