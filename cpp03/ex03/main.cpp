/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:39:42 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/16 13:39:42 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\nLet's create a ScavTrap" << std::endl;
	ScavTrap Scav("Scaffie");
	Scav.guardGate();
	std::cout << "\nAnd we create a FragTrap" << std::endl;
	FragTrap Frag("Fraggle");
	Frag.highFivesGuys();

	std::cout << "\nAnd we create a beautiful DiamondTrap now." << std::endl;
	DiamondTrap Diam("Sparkle");
	Diam.whoAmI();

	std::cout << "\nIt gets so annoying but all of them want to fight..." << std::endl;
	Diam.attack("Scaffie");
	Scav.takeDamage(Diam.getAttackDamage());
	Scav.beRepaired(Diam.getAttackDamage());
	Frag.attack("Sparkle");
	Diam.takeDamage(Frag.getAttackDamage());
	Diam.beRepaired(Frag.getAttackDamage());
	Scav.attack("Sparkle");
	Diam.takeDamage(Scav.getAttackDamage());
	Diam.beRepaired(Scav.getAttackDamage());

	std::cout << "\nNothing new here so we stop this silly exercise" << std::endl;
	return 0;
}
