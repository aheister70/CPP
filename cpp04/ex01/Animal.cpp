/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:14:17 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:14:17 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
	this->type = "Default animal";
	std::cout << "Default animal constructor is called." << std::endl;
	return;
}

Animal::Animal(Animal const & src) {
	std::cout << this->type << "Animal copy constructor." << std::endl;
	*this = src;
	return;
}

Animal& Animal::operator=(Animal const & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor of " << this->type << "." << std::endl;
	return;
}

std::string Animal::getType(void) const {
	return this->type;
}

void	Animal::makeSound(void) const {
	std::cout << "Silence ..." << std::endl;
}
