/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 15:08:50 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/19 15:08:50 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

/*
 * The Diamond Problem occurs when a child class inherits from two parent classes who
 * both share a common grandparent class. The solution to the diamond problem is to use
 * the virtual keyword. We make the two parent classes (who inherit from the same
 * grandparent class) into virtual classes in order to avoid two copies of the
 * grandparent class in the child class.
 */

DiamondTrap::DiamondTrap(std::string Name) : _Name(Name)
{
	ClapTrap::_Name = (this->_Name + "_clap_name");
	FragTrap::_MaxHitPoints = FragTrap::getHitPoints();
	FragTrap::_HitPoints = FragTrap::getHitPoints();
	ScavTrap::_EnergyPoints = ScavTrap::getEnergyPoints();
	FragTrap::_AttackDamage = FragTrap::getAttackDamage();
	std::cout << "DiamondTrap ";
	this->printStatus();
	std::cout << " starts his radiant life on earth" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	this->printStatus();
	std::cout << " has all copied parts now." << std::endl;
	*this = src;
	return;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
		this->_MaxHitPoints = rhs._MaxHitPoints;
		this->_HitPoints = rhs._HitPoints;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap ";
	this->printStatus();
	std::cout << " has stopped shining forever!" << std::endl;
	return;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am Diamond_name: " << this->_Name << " and ClapTrap_name: " << ClapTrap::getName() << std::endl;
}
