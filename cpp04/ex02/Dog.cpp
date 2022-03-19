/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:16:41 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:16:41 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void) {
	this->type = "Dog";
	this->_brain = new Brain();
	this->_brain->setIdea("I'm a dog, I'm a dog!!", 0);
	std::cout << "A dog is born." << std::endl;
	return;
}

Dog::Dog(Dog const & src)
	: AAnimal(src) {
	this->_brain = new Brain();
	*_brain = *(src._brain);
	std::cout << "A dog is copied deeeeep." << std::endl;
	return;
}

Dog& Dog::operator=(Dog const & rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		this->_brain = rhs._brain;
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "What a pity, we loose the dog's only idea: \"" << this->_brain->getIdea(0) << "\"." << std::endl;
	delete this->_brain;
	std::cout << "A dog died." << std::endl;
	return;
}

void	Dog::makeSound(void) const {
	std::cout << "Woooooooooooof!" << std::endl;
}
