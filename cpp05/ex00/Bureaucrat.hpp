/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 08:17:36 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/01 08:17:36 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_BUREAUCRAT_H
#define CPP05_BUREAUCRAT_H

#define GRNF "\x1b[32m"
#define RESET "\e[0m"

#include <string>

class Bureaucrat {
private:
	std::string const	_name;
	int 				_grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator=(Bureaucrat const & rhs);
	virtual ~Bureaucrat(void);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	std::string	const 	getName(void) const;
	int					getGrade(void) const;
	void 				incrementGrade(void);
	void 				decrementGrade(void);
	bool 				checkGrade(int grade);

};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & input);

#endif //CPP05_BUREAUCRAT_H
