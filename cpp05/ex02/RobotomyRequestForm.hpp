/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:49:02 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/02 16:49:02 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_ROBOTOMYREQUESTFORM_H
#define CPP05_ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
	virtual ~RobotomyRequestForm(void);

	virtual void execution(void) const;
};

#endif //CPP05_ROBOTOMYREQUESTFORM_H
