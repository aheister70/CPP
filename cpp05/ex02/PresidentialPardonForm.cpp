/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:49:55 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/02 16:49:55 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm("PresidentialPardon", 25, 5, target) {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
		: AForm(src) {
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if(this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return;
}

void PresidentialPardonForm::execution(void) const {
	std::cout << "From now on '" << this->getTarget() << "' has been pardoned by Zaphod Beeblebrox" << std::endl;
}
