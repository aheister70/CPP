/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/20 12:38:40 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/20 12:38:40 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_ANIMAL_H
#define CPP04_ANIMAL_H

#define GRNF "\x1b[32m"
#define RESET "\e[0m"

#include <string>

class Animal {
protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const & src);
	Animal& operator=(Animal const & rhs);
	virtual ~Animal(void);

	std::string 	getType(void) const;
	virtual void	makeSound(void) const;
};

#endif //CPP04_ANIMAL_H
