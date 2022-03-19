/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 15:48:18 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/01 15:48:18 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
 * A reference (alias) is used: when you want to just pass the value around instead
 * of copying the same variable into memory at a different location.
 * So, using a reference, copying can be avoidable which saves memory.
 * Use references when you can, and pointers when you have to. References are usually
 * preferred over pointers whenever you don't need “reseating”. This usually means that
 * references are most useful in a class's public interface. References typically
 * appear on the skin of an object, and pointers on the inside.
 */

int	main (void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "\nDisplaying the address of the string" << std::endl;
	std::cout << "&brain =      " << &brain << std::endl;
	std::cout << "stringPTR =   " << stringPTR << std::endl;
	std::cout << "&stringREF =  " << &stringREF << std::endl;
	std::cout << "\nDisplaying the content of the string" << std::endl;
	std::cout << "brain =       " << brain << std::endl;
	std::cout << "*stringPTR =  " << *stringPTR << std::endl;
	std::cout << "stringREF =   " << stringREF << std::endl;
	return 0;
}
