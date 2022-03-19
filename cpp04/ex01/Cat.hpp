/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:14:51 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:14:51 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_CAT_H
#define CPP04_CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* _brain;

public:
	Cat(void);
	Cat(Cat const & src);
	Cat& operator=(Cat const & rhs);
	virtual ~Cat(void);

	void	makeSound(void) const;
};

#endif //CPP04_CAT_H
