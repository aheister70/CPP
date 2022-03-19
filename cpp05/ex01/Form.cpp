/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 16:59:50 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/01 16:59:50 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("default form"), _signed(false), _gradeSign(1), _gradeExecute(1) {
	return;
}

Form::Form(std::string const & name, int gradeSign, int gradeExecute) : _name(name), _signed(false),
		_gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if (!checkGrade(_gradeSign))
		std::cout << " for the signGrade" << std::endl;
	if (!checkGrade(_gradeExecute))
		std::cout << " for the executionGrade" << std::endl;
	return;
}

Form::Form(Form const & src) : _signed(src._signed), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute) {
	if (!checkGrade(_gradeSign))
		std::cout << " for the signGrade" << std::endl;
	if (!checkGrade(_gradeExecute))
		std::cout << " for the executionGrade" << std::endl;
	return;
}

Form & Form::operator=(Form const & rhs) {
	if (this != &rhs) {
		this->_signed = rhs.getSigned();
	}
	return *this;
}

Form::~Form(void) {
	return;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade can't be higher than 1";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade can't be lower than 150";
}

const char *Form::FormSignGradeException::what() const throw() {
	return "The signGrade of the form is too high";
}

std::string const Form::getName(void) const {
	return this->_name;
}

bool Form::getSigned(void) const {
	return this->_signed;
}

int Form::getGradeSign(void) const {
	return this->_gradeSign;
}

int Form::getGradeExecute(void) const {
	return this->_gradeExecute;
}

bool Form::checkGrade(int grade) {
	try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		return true;
	}
	catch (GradeTooHighException& e) {
		std::cout << e.what();
		return false;
	}
	catch (GradeTooLowException& e) {
		std::cout << e.what();
		return false;
	}
}

bool Form::beSigned(Bureaucrat const & sign) {
	try {
		if (this->_gradeSign < sign.getGrade())
			throw FormSignGradeException();
		else
			this->_signed = true;
	}
	catch (FormSignGradeException& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

std::ostream & operator<<(std::ostream & out, Form const & input) {
	std::string status;
	if (input.getSigned() == true)
		status = "signed";
	else
		status = "unsigned";
	out << "Form '" << input.getName() << "' (" << status << "), signGrade: " << input.getGradeSign() <<
		", executionGrade: " << input.getGradeExecute();
	return out;
}
