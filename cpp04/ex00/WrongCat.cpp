/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 10:25:33 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 10:25:33 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "A wrong cat is born." << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const & src)
	: WrongAnimal(src) {
	std::cout << "A wrong cat is copied" << std::endl;
	return;
}

WrongCat& WrongCat::operator=(WrongCat const & rhs) {
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "A wrong cat died." << std::endl;
	return;
}

void WrongCat::makeSound(void) const {
	std::cout << "Meeeeeeoooooow!" << std::endl;
}