/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 10:20:26 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 10:20:26 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
	this->type = "Default wrong animal";
	std::cout << "Default wrong animal constructor is called." << std::endl;
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << this->type << " calls wrong animal copy constructor." << std::endl;
	*this = src;
	return;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Wrong animal destructor of " << this->type << "." << std::endl;
	return;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Silence......" << std::endl;
}
