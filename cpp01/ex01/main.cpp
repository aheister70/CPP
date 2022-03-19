/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 15:46:09 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/01 15:46:09 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

int	main (void) {
	std::string hordeName;
	std::string input_str;
	int 		input;
	Zombie* 	Horde = NULL;

	std::cout << "\nNow you are creating a zombie horde." << std::endl;
	while (hordeName.compare("") == 0)
	{
		std::cout << "Fill in the name of your zombie horde: ";
		std::getline(std::cin, hordeName);
		if (!std::cin)
			exit(0);
		if (hordeName.compare("") == 0)
			std::cout << REDF "Your input can't be empty." RESET << std::endl;
	}
	input = 0;
	while (input == 0)
	{
		std::cout << "\nFill in the size of your horde (between 2 and 20): ";
		std::getline(std::cin, input_str);
		if (!std::cin)
			exit(0);
		std::istringstream convert(input_str);
		convert >> input;
		if (input > 1 && input <= 20)
			Horde = zombieHorde(input, hordeName);
		else
		{
			std::cout << REDF "\nYour input: \"" << input << "\" is not valid." RESET << std::endl;
			input = 0;
		}
	}
	std::cout << GRNF "\nDue to safety reasons we have to immediately eliminate your horde \"" <<
			hordeName << "\": " RESET << std::endl;
	delete [] Horde;
	return 0;
}
