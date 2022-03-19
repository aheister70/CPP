/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 11:09:08 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/07 11:09:08 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_INTERN_H
#define CPP05_INTERN_H

#include "AForm.hpp"
#include <string>

class Intern {
public:
	Intern(void);
	Intern(Intern const & src);
	Intern & operator=(Intern const & rhs);
	virtual ~Intern(void);

	class FormNotExistsException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	AForm* makeForm(std::string type, std::string target);
	AForm* createPresidentialPardonForm(std::string target);
	AForm* createRobotomyRequestForm(std::string target);
	AForm* createShrubberyCreationForm(std::string target);
};


#endif //CPP05_INTERN_H
