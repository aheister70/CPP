/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 09:26:35 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/23 09:26:35 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource::MateriaSource(void)
	: _amount(0) {
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
	return;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
	return;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs) {
		this->_amount = rhs._amount;
		for (int i = 0; i < this->_amount; i++)
			this->_materias[i] = rhs._materias[i];
	}
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < this->_amount; i++)
		delete this->_materias[i];
	return;
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (this->_amount < 4 && materia != nullptr) {
		this->_materias[_amount] = materia;
		this->_amount += 1;
	}
	else if (this->_amount == 4) {
		delete materia;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_amount; i++) {
		if (this->_materias[i]->getType().compare(type) == 0)
			return this->_materias[i]->clone();
	}
	return 0;
}

void MateriaSource::showMateria(void) {
	for (int i = 0; i < this->_amount; i++) {
		std::cout << i + 1 << ". " << this->_materias[i]->getType() << std::endl;
	}
}
