/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClassContact.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 13:48:39 by aheister      #+#    #+#                 */
/*   Updated: 2022/01/20 13:48:39 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClassContact.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

std::string	Contact::_adjust_format(std::string input) {
	int 		len;
	std::string	empty;

	len = input.length();
	if (len > 10) {
		input.resize(9);
		input.resize(10, '.');
	}
	else {
		empty.resize((10 - len), ' ');
		empty.append(input);
		input = empty;
	}
	return input;
}

void	Contact::print_contact_short(void) {
	std::cout << "    |" << this->_adjust_format(std::to_string(this->_idx));
	std::cout << "|" << this->_adjust_format(this->_firstName);
	std::cout << "|" << this->_adjust_format(this->_lastName);
	std::cout << "|" << this->_adjust_format(this->_nickName) << "|    " << std::endl;
}

void	Contact::print_contact(void) {
	std::cout << "\n";
	std::cout << "First name:	" << GRNF << this->_firstName << RESET << std::endl;
	std::cout << "Last name:	" << GRNF << this->_lastName << RESET << std::endl;
	std::cout << "Nick name:	" << GRNF << this->_nickName << RESET << std::endl;
	std::cout << "Phone number:	" << GRNF << this->_phoneNumber << RESET << std::endl;
	std::cout << "Darkest secret:	" << GRNF << this->_darkestSecret << RESET << std::endl;
}

void	Contact::_set_values(int idx, std::string fN, std::string lN, std::string nN, std::string pN, std::string dS) {
	this->_idx = idx + 1;
	this->_firstName = fN;
	this->_lastName = lN;
	this->_nickName = nN;
	this->_phoneNumber = pN;
	this->_darkestSecret = dS;

	std::cout << GRNF "\nYour contact has been saved." RESET << std::endl;
}

std::string Contact::get_input(std::string input) {
	std::getline(std::cin, input);
	if (!std::cin)
		exit(0);
	else if (input.compare("") == 0)
		std::cout << REDF "Your input can't be empty." RESET << std::endl;
	return input;
}

int	Contact::add_contact(int idx) {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string choice;

	std::cout << "\n";
	std::cout << BLUB " *                  ADD a contact                  * " RESET << "\n"<< std::endl;
	while (firstName.compare("") == 0) {
		std::cout << "First name:	";
		firstName = this->get_input(firstName);
	}
	while (lastName.compare("") == 0) {
		std::cout << "Last name:	";
		lastName = this->get_input(lastName);
	}
	while (nickName.compare("") == 0) {
		std::cout << "Nick name:	";
		nickName = this->get_input(nickName);
	}
	while (phoneNumber.compare("") == 0) {
		std::cout << "Phone number:	";
		phoneNumber = this->get_input(phoneNumber);
	}
	while (darkestSecret.compare("") == 0) {
		std::cout << "Darkest secret:	";
		darkestSecret = this->get_input(darkestSecret);
	}
	while ((choice.compare("Y") != 0) || (choice.compare("N") != 0)) {
		std::cout << "\nPlease check your input. Do you want to save this contact? Y/N " << std::endl;
		std::getline(std::cin, choice);
		if (choice.compare("Y") == 0) {
			this->_set_values(idx, firstName, lastName, nickName, phoneNumber, darkestSecret);
			return 0;
		}
		else if (choice.compare("N") == 0) {
			std::cout << GRNF "\nYour contact has been removed." RESET << std::endl;
			return 1;
		}
		else
			std::cout << REDF "\nYour input: \"" << choice << "\" is not valid." RESET << std::endl;
	}
	return 0;
}
