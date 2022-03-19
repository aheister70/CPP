/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 16:59:43 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/01 16:59:43 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_FORM_H
#define CPP05_FORM_H

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
private:
	std::string const 	_name;
	bool 				_signed;
	int const			_gradeSign;
	int const			_gradeExecute;

	Form(void);

public:
	Form(std::string const & name, int gradeSign, int gradeExecute);
	Form(Form const & src);
	Form & operator=(Form const & rhs);
	virtual ~Form(void);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormSignGradeException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	std::string const	getName(void) const;
	bool				getSigned(void) const;
	int					getGradeSign(void) const;
	int					getGradeExecute(void) const;
	bool 				checkGrade(int grade);
	bool 				beSigned(Bureaucrat const & sign);
};

std::ostream & operator<<(std::ostream & out, Form const & form);


#endif //CPP05_FORM_H
