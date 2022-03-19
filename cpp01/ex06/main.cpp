/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:47:57 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/05 18:47:57 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

enum level {
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3
};

int main(int argc, char* argv[])
{
	int 		idx;
	Karen		Karen;
	std::string input;
	std::string	complaint[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	if (argc == 2)
	{
		for (size_t i = 0; i < strlen(argv[1]); i++)
			input.append(1, argv[1][i]);
		idx = 0;
		while (input.compare(complaint[idx]) != 0 && idx < 4)
			idx++;
		switch (idx)
		{
			case DEBUG:
				std::cout << "[ DEBUG ]" << std::endl;
				Karen.complain("DEBUG");
			case INFO:
				std::cout << "[ INFO ]" << std::endl;
				Karen.complain("INFO");
			case WARNING:
				std::cout << "[ WARNING ]" << std::endl;
				Karen.complain("WARNING");
			case ERROR:
				std::cout << "[ ERROR ]" << std::endl;
				Karen.complain("ERROR");
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
		}
	}
	else
		std::cout << REDF "Error: no arguments" RESET << std::endl;
	return 0;
}
