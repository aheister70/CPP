/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:48:16 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/02 16:48:16 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_SHRUBBERYCREATIONFORM_H
#define CPP05_SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
	virtual ~ShrubberyCreationForm(void);

	virtual void execution(void) const;
};

#endif //CPP05_SHRUBBERYCREATIONFORM_H
