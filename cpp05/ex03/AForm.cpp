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

#include "AForm.hpp"
#include <iostream>

AForm::AForm(void)
	: _name("default form"), _signed(false), _gradeSign(1), _gradeExecute(1) {
	return;
}

AForm::AForm(std::string const & name, int gradeSign, int gradeExecute, std::string target)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _target(target) {
	if (!checkGrade(_gradeSign))
		std::cout << " for the signGrade" << std::endl;
	if (!checkGrade(_gradeExecute))
		std::cout << " for the executionGrade" << std::endl;
	return;
}

AForm::AForm(AForm const & src)
	: _signed(src._signed), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute), _target(src._target) {
	if (!checkGrade(_gradeSign))
		std::cout << " for the signGrade" << std::endl;
	if (!checkGrade(_gradeExecute))
		std::cout << " for the executionGrade" << std::endl;
	return;
}

AForm & AForm::operator=(AForm const & rhs) {
	if (this != &rhs) {
		this->_signed = rhs.getSigned();
	}
	return *this;
}

AForm::~AForm(void) {
	return;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade can't be higher than 1";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade can't be lower than 150";
}

const char *AForm::FormSignGradeException::what() const throw() {
	return "The signGrade of the form is too high";
}

const char *AForm::FormExecutionGradeException::what() const throw() {
	return "The executionGrade of the form is too high";
}

std::string const AForm::getName(void) const {
	return this->_name;
}

bool AForm::getSigned(void) const {
	return this->_signed;
}

int AForm::getGradeSign(void) const {
	return this->_gradeSign;
}

int AForm::getGradeExecute(void) const {
	return this->_gradeExecute;
}

std::string AForm::getTarget(void) const {
	return this->_target;
}

bool AForm::checkGrade(int grade) {
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

bool AForm::beSigned(Bureaucrat const & signer) {
	try {
		if (this->_gradeSign < signer.getGrade())
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

bool AForm::execute(Bureaucrat const & executor) const {
	try {
		if (this->_gradeExecute < executor.getGrade())
			throw FormExecutionGradeException();
		else
			this->execution();
	}
	catch (FormExecutionGradeException& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

/*
 * Since an Intern can make forms, there is the option that a form cannot be created and only a nullptr is
 * sent to the stream operator function. If you try to print a nullptr, you get a segfault. To avoid this
 * the function is adjusted to check if the form exists.
 */

std::ostream & operator<<(std::ostream & out, AForm const & input) {
	std::string status;
	if (&input == nullptr)
		out << "Form cannot be printed because it doesn't exist";
	else {
		if (input.getSigned() == true)
			status = "signed";
		else
			status = "unsigned";
		out << "Form '" << input.getName() << "' (" << status << "), signGrade: " << input.getGradeSign() <<
			", executionGrade: " << input.getGradeExecute() << ", target: " << input.getTarget();
	}
	return out;
}
