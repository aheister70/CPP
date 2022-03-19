/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 15:46:19 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/01 15:46:19 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

std::string names[20] = { "Albert", "Ash", "Billy", "Boston", "Bub", "Papa Dre", "Ed", "Fido", "Julie"
		, "Karen", "Liv", "Madeline", "Mama Merle", "Moonbeam", "Murphy", "Pete"
		, "Randall", "Sheila", "Salomon", "Sophia" };

Zombie::Zombie(void) : _name(names[rand() % 19])
{
	this->announce();
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << this->_name << "\" died... RIP" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
