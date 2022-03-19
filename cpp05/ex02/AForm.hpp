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

#ifndef CPP05_AFORM_H
#define CPP05_AFORM_H

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm {
private:
	std::string const 	_name;
	bool 				_signed;
	int const			_gradeSign;
	int const			_gradeExecute;
	std::string 		_target;

	AForm(void);

public:
	AForm(std::string const & name, int gradeSign, int gradeExecute, std::string target);
	AForm(AForm const & src);
	AForm & operator=(AForm const & rhs);
	virtual ~AForm(void);

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

	class FormExecutionGradeException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	std::string const	getName(void) const;
	bool				getSigned(void) const;
	int					getGradeSign(void) const;
	int					getGradeExecute(void) const;
	std::string			getTarget(void) const;
	bool 				checkGrade(int grade);
	bool 				beSigned(Bureaucrat const & signer);
	bool				execute(Bureaucrat const & executor) const;
	virtual void 		execution(void) const = 0;
};

std::ostream & operator<<(std::ostream & out, AForm const & form);

#endif //CPP05_AFORM_H
