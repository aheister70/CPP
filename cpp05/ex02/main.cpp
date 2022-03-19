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
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void) {
	std::cout << GRNF "We create bureaucrat 'Highy' with grade 3" RESET << std::endl;
	Bureaucrat* High = new Bureaucrat("Highy", 3);
	std::cout << *High << std::endl;
	std::cout << GRNF "And we create bureaucrat 'Lowie' with grade 23" RESET << std::endl;
	Bureaucrat* Low = new Bureaucrat("Lowie", 23);
	std::cout << *Low << std::endl;

	std::cout << GRNF "\nThen we create a PresidentialPardon form" RESET << std::endl;
	AForm* P1 = new PresidentialPardonForm("Flynn");
	std::cout << *P1 << std::endl;
	std::cout << GRNF "\nHighy tries to execute the PresidentialPardon form" RESET << std::endl;
	High->executeForm(*P1);
	std::cout << *P1 << std::endl;
	Low->signForm(*P1);
	std::cout << GRNF "\nHighy tries again to execute the PresidentialPardon form" RESET << std::endl;
	High->executeForm(*P1);

	std::cout << GRNF "\nLet's create a RobotomyRequest form" RESET << std::endl;
	AForm* R1 = new RobotomyRequestForm("rabbit");
	std::cout << *R1 << std::endl;
	Low->signForm(*R1);
	High->executeForm(*R1);

	std::cout << GRNF "\nLet's create a ShrubberyCreation form" RESET << std::endl;
	AForm* S1 = new ShrubberyCreationForm("class room");
	std::cout << *R1 << std::endl;
	Low->signForm(*S1);
	High->executeForm(*S1);

	delete High;
	delete Low;
	delete P1;
	delete R1;
//	system ("leaks bureaucrat");
	return 0;
}
