/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:47:17 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:47:17 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void)
	: AMateria("cure") {
	return;
}

Cure::Cure(std::string const & type) : AMateria(type) {
	return;
}

Cure::Cure(Cure const & src)
	: AMateria(src) {
	return;
}

Cure& Cure::operator=(Cure const & rhs) {
	AMateria::operator=(rhs);
	return *this;
}

Cure::~Cure(void) {}

AMateria* Cure::clone(void) const {
	AMateria* cure = new Cure(*this);
	return cure;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
