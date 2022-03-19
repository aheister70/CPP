/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:47:23 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:47:23 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

/*
 * In de constructor van de derived Ice roep je direct de constructor van de base Materia aan
 * Eventuele waardes van variabelen kun je verder in de functie toekennen.
 */

Ice::Ice(void)
	: AMateria("ice") {
	return;
}

Ice::Ice(std::string const & type)
	: AMateria(type) {
	return;
}

Ice::Ice(Ice const & src)
	: AMateria(src) {
	return;
}

Ice& Ice::operator=(Ice const & rhs) {
	AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice(void) {}

AMateria* Ice::clone(void) const {
	AMateria* ice = new Ice(*this);
	return ice;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
