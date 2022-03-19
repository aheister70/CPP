/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/20 13:40:43 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/20 13:40:43 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

/*
 * In case ‘j’ I create an Animal by defining a new Dog. My dog has without adjusting
 * the code the behaviour of an animal, not a dog. That means that overloading the makeSound
 * function in the Dog class is not working, the dog would still remain silent. If you add the
 * 'virtual' keyword to the makeSound function of the Animal, the program searches for the
 * makeSound function in the class where the function is called.
 */

int main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << GRNF "\nWe make a wrong animal and cat to prove what can go wrong." RESET << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* catwrong = new WrongCat();

	std::cout << catwrong->getType() << " " << std::endl;
	catwrong->makeSound();
	wrong->makeSound();

	std::cout << GRNF "\nUnfortunately they all die." RESET << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete catwrong;
	return 0;
}
