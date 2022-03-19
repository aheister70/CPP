/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 11:09:13 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/07 11:09:13 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void) {
	return;
}

Intern::Intern(Intern const & src) {
	*this = src;
	return;
}

Intern & Intern::operator=(Intern const & rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

Intern::~Intern(void) {
	return;
}

const char *Intern::FormNotExistsException::what() const throw() {
	return "This type of form doesn't exist";
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string type, std::string target) {
	AForm *F;
	int idx;
	AForm* (Intern::*ptr[])(std::string) = { &Intern::createPresidentialPardonForm,
			&Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm };
	std::string formType[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };

	F = nullptr;
	idx = 0;
	try {
		for (int i = 0; i < 3; i++) {
			if (type.compare(formType[i]) == 0) {
				F = (this->*ptr[i])(target);
				idx = 1;
			}
		}
		if (idx == 0)
			throw FormNotExistsException();
	}
	catch (FormNotExistsException& e) {
		std::cout << e.what() << std::endl;
	}
	return F;
}
