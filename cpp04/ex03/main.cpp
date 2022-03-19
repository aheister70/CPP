/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:17:48 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:17:48 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

#define GRNF "\x1b[32m"
#define REDF "\x1b[31m"
#define RESET "\e[0m"

/*
 * You should be careful in which files you put the header files. If you put them everywhere (double)
 * the program won't compile and complains about not finding a header file.
 */

int main()
{
	std::cout << GRNF "\nWe add 4 Materia to the source" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->showMateria();
	std::cout << GRNF "\nAdding a fifth Materia to the source : " RESET << std::endl;
	src->learnMateria(new Ice());
	std::cout << REDF "This is not possible because there are only 4 slots" RESET << std::endl;

	src->showMateria();

	std::cout << GRNF "We create character 'me'" RESET << std::endl;
	ICharacter* me = new Character("me");
	std::cout << GRNF "And we equip 'me' with 4 Materia" RESET << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << GRNF "\nAdding a fifth Materia to the inventory : " RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << REDF "This is not possible because there are only 4 slots" RESET << std::endl;

	std::cout << GRNF "\nTrying to create an unexisting material: " RESET << std::endl;
	tmp = src->createMateria("fire");
	if (tmp == 0)
		std::cout << GRNF "This materia cannot be created because it is not stored in the source\n" RESET << std::endl;
	ICharacter* bob = new Character("bob");
	Character* sandra = new Character();
	tmp = src->createMateria("ice");
	sandra->equip(tmp);
	Character* lisa = new Character(*sandra);
	lisa->use(0, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->unequip(1);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
//	system ("leaks materia");
	return 0;
}
