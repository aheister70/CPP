/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:10:46 by annaheister   #+#    #+#                 */
/*   Updated: 2022/01/27 16:10:46 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	this->announce();
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << this->_name << "\" died... RIP\n" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
