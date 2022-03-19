/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 08:17:42 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/01 08:17:42 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void) {
	std::cout << GRNF "\nWe create an Intern to create forms" RESET << std::endl;
	Intern *someRandomIntern = new Intern();
	AForm* FF1;
	std::cout << GRNF "The intern creates a valid form" RESET << std::endl;
	FF1 = someRandomIntern->makeForm("robotomy request", "Bender");
	std::cout << *FF1 << std::endl;
	AForm* FF2;
	std::cout << GRNF "\nThe intern creates a invalid form" RESET << std::endl;
	FF2 = someRandomIntern->makeForm("non existing form", "Rubbish");
	std::cout << *FF2 << std::endl;
	AForm* FF3;
	std::cout << GRNF "\nThe intern creates again a valid form" RESET << std::endl;
	FF3 = someRandomIntern->makeForm("presidential pardon", "Bob");
	std::cout << *FF3 << std::endl;

	std::cout << GRNF "\nWe create bureaucrat 'Highy' with grade 3" RESET << std::endl;
	Bureaucrat* High = new Bureaucrat("Highy", 3);
	std::cout << *High << std::endl;
	std::cout << GRNF "\n'Highy' signs and executes the last form" RESET << std::endl;
	High->signForm(*FF3);
	High->executeForm(*FF3);

	delete High;
	delete someRandomIntern;
	delete FF1;
	delete FF2;
	delete FF3;
//	system ("leaks bureaucrat");
	return 0;
}
