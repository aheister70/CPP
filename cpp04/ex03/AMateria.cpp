/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:17:41 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:17:41 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) {
	return;
}

AMateria::AMateria(std::string const & type) : type(type) {
	return;
}

AMateria::AMateria(AMateria const & src) {
	*this = src;
	return;
}

AMateria& AMateria::operator=(AMateria const & rhs) {
	this->type = rhs.type;
	return *this;
}

AMateria::~AMateria(void) {
	return;
}

std::string const & AMateria::getType(void) const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* does nothing to " << target.getName() << " *" << std::endl;
}
