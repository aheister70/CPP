/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:15:39 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:15:39 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_ANIMAL_H
#define CPP04_ANIMAL_H

#define GRNF "\x1b[32m"
#define RESET "\e[0m"

#include <string>
#include "Brain.hpp"

/*
 * A class that contains one or more pure virtual function(s) is known as an abstract class.
 * Pure virtual functions are used if a function doesn't have any use in the base class but
 * the function must be implemented by all its derived classes. We cannot create objects
 * of an abstract class. However, we can derive classes from them, and use their data members
 * and member functions (except pure virtual functions).
 */

class AAnimal {
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(AAnimal const & src);
	AAnimal& operator=(AAnimal const & rhs);
	virtual ~AAnimal(void);

	std::string 	getType(void) const;
	virtual void	makeSound(void) const = 0;
};

#endif //CPP04_ANIMAL_H
