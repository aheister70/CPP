/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:49:49 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/02 16:49:49 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_PRESIDENTIALPARDONFORM_H
#define CPP05_PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
	virtual ~PresidentialPardonForm(void);

	virtual void execution(void) const;
};

#endif //CPP05_PRESIDENTIALPARDONFORM_H
