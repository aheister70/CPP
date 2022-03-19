/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 08:17:30 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/01 08:17:30 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("default bureaucrat"), _grade(150) {
	return;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name) {
	if (checkGrade(grade))
		this->_grade = grade;
	else
		this->_grade = 150;
	return;
}

/*
 * It is not possible to create a bureaucrat with an unvalid grade or to change the grade
 * to an invalid number. Therefore if you copy a bureaucrat it is not necessary to check
 * if the grade is valid.
 */

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
	return;
}

/*
 * It is not possible to create a bureaucrat with an unvalid grade or to change the grade
 * to an invalid number. Therefore if you assign a grade from one to another it is not
 * necessary to check if the grade is valid.
 */

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	return;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade can't be higher than 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade can't be lower than 150";
}

std::string	const Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::incrementGrade(void) {
	if (checkGrade(this->_grade - 1))
		this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
	if (checkGrade(this->_grade + 1))
		this->_grade += 1;
}

bool Bureaucrat::checkGrade(int grade) {
	try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		return true;
	}
	catch (GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	catch (GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & input) {
	out << input.getName() << ", bureaucrat grade " << input.getGrade();
	return out;
}
