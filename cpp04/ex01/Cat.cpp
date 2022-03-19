/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:14:44 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:14:44 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void) {
	this->type = "Cat";
	this->_brain = new Brain();
	this->_brain->setIdea("Wow I am actually a cat", 0);
	std::cout << "A cat is born." << std::endl;
	return;
}

Cat::Cat(Cat const & src)
	: Animal(src) {
	this->_brain = new Brain();
	*_brain = *(src._brain);
	std::cout << "A cat is copied" << std::endl;
	return;
}

Cat& Cat::operator=(Cat const & rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		this->_brain = rhs._brain;
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "What a pity, we loose the cat's only idea: \"" << this->_brain->getIdea(0) << "\"." << std::endl;
	delete this->_brain;
	std::cout << "A cat died." << std::endl;
	return;
}

void	Cat::makeSound(void) const {
	std::cout << "Meeeeeeeooooooow!" << std::endl;
}
