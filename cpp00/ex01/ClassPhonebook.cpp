/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 13:39:09 by aheister      #+#    #+#                 */
/*   Updated: 2021/11/07 13:39:10 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "ClassPhonebook.hpp"

Phonebook::Phonebook(void) {
	std::cout << "\n";
	std::cout << BLUB " *************************************************** " RESET << std::endl;
	std::cout << BLUB " *                                                 * " RESET << std::endl;
	std::cout << BLUB " *     WELCOME to your awesome phonebook!          * " RESET << std::endl;
	std::cout << BLUB " *     You can use the following commands:         * " RESET << std::endl;
	std::cout << BLUB " *                                                 * " RESET << std::endl;
	std::cout << BLUB " *     ADD - to add a contact                      * " RESET << std::endl;
	std::cout << BLUB " *     SEARCH - to search through your contacts    * " RESET << std::endl;
	std::cout << BLUB " *     EXIT - to leave your phonebook              * " RESET << std::endl;
	std::cout << BLUB " *                                                 * " RESET << std::endl;
	std::cout << BLUB " *************************************************** " RESET << std::endl;
	this->_full = 0;
	input_command();
	return;
}

Phonebook::~Phonebook(void) {
	std::cout << "\n";
	std::cout << BLUB " *************************************************** " RESET << std::endl;
	std::cout << BLUB " *     THANKS for using your awesome phonebook.    * " RESET << std::endl;
	std::cout << BLUB " *               See you next time!                * " RESET << std::endl;
	std::cout << BLUB " *                                                 * " RESET << std::endl;
	std::cout << BLUB " *      We deleted all your contacts. Sorry ;-)    * " RESET << std::endl;
	std::cout << BLUB " *************************************************** " RESET << std::endl;
	std::cout << "\n";
	return;
}

void Phonebook::search_contacts(int nb) {
	std::string		input_str;
	int				input;

	std::cout << "\n" ;
	std::cout << BLUB " *                 SEARCH a contact                * " RESET << "\n"<< std::endl;
	std::cout << "    |----------|----------|----------|----------|    " << std::endl;
	std::cout << "    |     index|first name| last name| nick name|    " << std::endl;
	std::cout << "    |----------|----------|----------|----------|    " << std::endl;
	for (int idx = 0; idx < nb; idx++) {
		this->_contacts[idx].print_contact_short();
	}
	std::cout << "    |----------|----------|----------|----------|    " << std::endl;
	input = 0;
	while (input == 0) {
		std::cout << "\nFrom which contact do you want the information?" << std::endl;
		std::cout << "Please enter a number: ";
		std::getline(std::cin, input_str);
		if (!std::cin)
			exit(0);
		std::istringstream convert(input_str);
		convert >> input;
		if (input > 0 && input <= nb)
			this->_contacts[input - 1].print_contact();
		else {
			std::cout << REDF "\nYour input: \"" << input_str << "\" is not valid." RESET << std::endl;
			input = 0;
		}
	}
}

int Phonebook::add_contacts(int idx) {
	std::string	choice;

	if (idx == 8) {
		if (this->_full == 0) {
			std::cout << GRNF "\nYou have reached the maximum of 8 contacts." RESET << std::endl;
			std::cout << GRNF "From now on if you add another contact it will overwrite the oldest one." RESET
					  << std::endl;
			while ((choice.compare("Y") != 0) || (choice.compare("N") != 0)) {
				std::cout << "\nDo you want to continue? Y/N" << std::endl;
				std::getline(std::cin, choice);
				if (choice.compare("N") == 0)
					return idx;
				else if (choice.compare("Y") == 0) {
					this->_full = 1;
					break;
				}
				else
					std::cout << REDF "\nYour input: \"" << choice << "\" is not valid." RESET << std::endl;
			}
		}
		idx = 0;
	}
	if (this->_contacts[idx].add_contact(idx) == 0) {
		idx += 1;
	}
	return idx;
}

void Phonebook::input_command(void) {
	int			idx;
	int 		nb;
	std::string	command;

	idx = 0;
	while (command.compare("EXIT") != 0) {
		std::cout << "\nWhat do you want to do?" << std::endl;
		std::cout << "Please enter your command: ";
		std::getline(std::cin, command);
		if (!std::cin)
			exit(0);
		if (command.compare("ADD") == 0) {
			idx = this->add_contacts(idx);
		}
		else if (command.compare("SEARCH") == 0) {
			if (this->_full == 1 || idx > 0) {
				if (this->_full == 1)
					nb = 8;
				else
					nb = idx;
				this->search_contacts(nb);
			}
			else {
				std::cout << GRNF "\nThere are no contacts yet to search through." RESET << std::endl;
				std::cout << GRNF "Enter ADD to add a contact." RESET << std::endl;
			}
		}
		else if (command.compare("EXIT") == 0)
			return;
		else {
			std::cout << REDF "\nYour input: \"" << command << "\" is not valid." RESET << std::endl;
			std::cout << "You can use the following commands: ADD, SEARCH, EXIT." << std::endl;
		}
	}
}
