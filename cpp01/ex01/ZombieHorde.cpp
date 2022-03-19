/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 15:47:40 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/01 15:47:40 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std::string name)
{
	std::cout << GRNF "\nMeet your horde \"" << name << "\": " RESET << std::endl;
	Zombie* zombies = new Zombie[N];
	return zombies;
}
