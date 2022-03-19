/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:14:03 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:14:03 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) {
	this->type = "Default animal";
	std::cout << "Default Animal constructor is called." << std::endl;
	return;
}

AAnimal::AAnimal(AAnimal const & src) {
	std::cout << this->type << "Animal copy constructor." << std::endl;
	*this = src;
	return;
}

AAnimal& AAnimal::operator=(AAnimal const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal destructor of " << this->type << "." << std::endl;
	return;
}

std::string AAnimal::getType(void) const {
	return this->type;
}
