/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:32:27 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/12 13:32:27 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\nLet's create 2 ClapTraps:" << std::endl;
	ClapTrap Clap("Clap");
	ClapTrap Trap("Trap");

	std::cout << "\nUnfortunately ClapTraps always want to fight (boring...)" << std::endl;
	while (Clap.getEnergyPoints() > 2 && Trap.getEnergyPoints() > 2)
	{
		Clap.attack("Trap");
		Trap.takeDamage(Clap.getAttackDamage());
		Trap.beRepaired(Clap.getAttackDamage());
		Trap.attack("Clap");
		Clap.takeDamage(Trap.getAttackDamage());
		Clap.beRepaired(Trap.getAttackDamage());
	}
	Clap.attack("Trap");
	std::cout << ("\nLet's assume now that the Attack Damage was 5 Hit Points") << std::endl;
	Trap.takeDamage(5);
	Trap.beRepaired(5);
	Trap.attack("Clap");
	Clap.takeDamage(5);
	Clap.beRepaired(5);
	Clap.attack("Trap");
	Trap.takeDamage(Clap.getAttackDamage());
	Trap.beRepaired(Clap.getAttackDamage());
	return 0;
}
