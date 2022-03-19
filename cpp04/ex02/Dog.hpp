/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:16:48 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:16:48 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_DOG_H
#define CPP04_DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
	Brain* _brain;

public:
	Dog(void);
	Dog(Dog const & src);
	Dog& operator=(Dog const & rhs);
	virtual ~Dog(void);

	virtual void	makeSound(void) const;
};

#endif //CPP04_DOG_H
