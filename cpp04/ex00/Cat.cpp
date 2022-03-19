/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/20 13:08:30 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/20 13:08:30 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "A cat is born." << std::endl;
	return;
}

Cat::Cat(Cat const & src)
	: Animal(src) {
	std::cout << "A cat is copied" << std::endl;
	return;
}

Cat& Cat::operator=(Cat const & rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

Cat::~Cat(void) {
	std::cout << "A cat died." << std::endl;
	return;
}

void	Cat::makeSound(void) const {
	std::cout << "Meeeeeeeooooooow!" << std::endl;
}
