/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:16:53 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:16:53 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void) {
	const AAnimal* animals[4];

	std::cout << GRNF "\nLet's create 4 animals: " RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog;
			animals[i]->makeSound();
		}
		else {
			animals[i] = new Cat;
			animals[i]->makeSound();
		}
	}

	std::cout << GRNF "\nTo test if the program can create deep copies, we create a copy of a dog: " RESET << std::endl;
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog(*dog1);

	std::cout << GRNF "\nWe look at the address of the 2 dogs. In case of a copy, these have to differ" RESET << std::endl;
	std::cout << "Address of dog 1 " << &dog1 << std::endl;
	std::cout << "Address of dog 2 " << &dog2 << std::endl;
	std::cout << GRNF "\nWe have to let the 2 dogs go now" RESET << std::endl;
	delete dog1;
	delete dog2;

	std::cout << GRNF "\nUnfortunately we have to let the animals go" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
