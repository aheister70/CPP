/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:10:25 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/09 18:01:58 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	std::string nameZombie;
	std::string nameRandomChump;
	Zombie* realZombie = NULL;

	std::cout << GRNF"\nToday you are going to create 2 zombies." << std::endl;
	std::cout << "Your first zombie is a proper zombie, created on the heap." << std::endl;
	std::cout << "We can kill it anytime without killing the whole program.\n" RESET << std::endl;
	while (nameZombie.compare("") == 0)
	{
		std::cout << "Fill in the name of your zombie: ";
		std::getline(std::cin, nameZombie);
		if (!std::cin)
			exit(0);
		if (nameZombie.compare("") == 0)
			std::cout << REDF "Your input can't be empty." RESET << std::endl;
	}
	realZombie = newZombie(nameZombie);
	std::cout << "We now kill " << nameZombie << "." << std::endl;
	delete realZombie;
	std::cout << GRNF "Your second zombie is a randomChump zombie, created on the stack." << std::endl;
	std::cout << "Killing this zombie means killing the whole program.\n" RESET << std::endl;
	while (nameRandomChump.compare("") == 0)
	{
		std::cout << "Fill in the name of your randomChump: ";
		std::getline(std::cin, nameRandomChump);
		if (!std::cin)
			exit(0);
		if (nameRandomChump.compare("") == 0)
			std::cout << REDF "Your input can't be empty." RESET << std::endl;
	}
	randomChump(nameRandomChump);
	return 0;
}
