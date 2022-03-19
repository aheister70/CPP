/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 11:09:59 by aheister      #+#    #+#                 */
/*   Updated: 2022/02/03 11:09:59 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>
#include <sstream>

int main(void)
{
	int 		input;
	std::string input_str;
	Karen		Karen;
	std::string	complaint[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	std::cout << "\nMeet Karen. Karen complaints A LOT!" << std::endl;
	input = 0;
	while (input == 0)
	{
		std::cout << "How many complaints do you want to hear from Karen (between 1 and 20): ";
		std::getline(std::cin, input_str);
		if (!std::cin)
			exit(0);
		std::istringstream convert(input_str);
		convert >> input;
		srand(time(0));
		if (input > 0 && input <= 20)
		 {
			 for (int idx = 0; idx < input; idx++)
				 Karen.complain(complaint[rand() % 4]);
		 }
		else
		{
			std::cout << REDF "\nYour input: \"" << input << "\" is not valid." RESET << std::endl;
			input = 0;
		}
	}
	return 0;
}
