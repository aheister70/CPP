/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 14:06:58 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/14 14:06:58 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\nLet's create 2 ClapTraps:" << std::endl;
	ClapTrap Clap("Clap");
	ClapTrap Trap("Trap");

	std::cout << "\nUnfortunately ClapTraps always want to fight (boring...)" << std::endl;
	Clap.attack("Trap");
	Trap.takeDamage(Clap.getAttackDamage());
	Trap.beRepaired(Clap.getAttackDamage());
	Trap.attack("Clap");
	Clap.takeDamage(Trap.getAttackDamage());
	Clap.beRepaired(Trap.getAttackDamage());

	std::cout << "\nLet's create a ScavTrap. ScavTraps are even worse... (super boring)" << std::endl;
	ScavTrap Scav("Scaffie");
	Scav.attack("Clap");
	Clap.takeDamage(Scav.getAttackDamage());
	Clap.beRepaired(Scav.getAttackDamage());
	Scav.guardGate();
	std::cout << "\nWe really have to stop this stupid fight!" << std::endl;
	return 0;
}
