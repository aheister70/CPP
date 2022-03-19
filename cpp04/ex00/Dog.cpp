/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/20 13:37:16 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/20 13:37:16 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
	this->type = "Dog";
	std::cout << "A dog is born." << std::endl;
	return;
}

Dog::Dog(Dog const & src)
	: Animal(src) {
	std::cout << "A dog is copied" << std::endl;
	return;
}

Dog& Dog::operator=(Dog const & rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

Dog::~Dog(void) {
	std::cout << "A dog died." << std::endl;
	return;
}

void	Dog::makeSound(void) const {
	std::cout << "Woooooooooooof!" << std::endl;
}
