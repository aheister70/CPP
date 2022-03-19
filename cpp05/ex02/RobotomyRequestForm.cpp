/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:49:08 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/02 16:49:08 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm("RobotomyRequest", 72, 45, target) {
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
		: AForm(src) {
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if(this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return;
}

void RobotomyRequestForm::execution(void) const {
	int nb;

	srand(time(0));
	std::cout << "Rizzzzzzzz Buzzzzzzzzz Rizz Buzz " << std::endl;
	nb = rand() % 2;
	if (nb == 1)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy of " << this->getTarget() << " failed" << std::endl;
}
