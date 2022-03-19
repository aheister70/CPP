/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 14:09:47 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/14 14:09:47 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/*
 * The member attributes in the header file of the ClapTrap class (_Name, _HitPoints etc)
 * are replaced to the level protected: to enable both the ClapTrap class and the derived
 * to directly access them.
 */

ScavTrap::ScavTrap(std::string Name)
{
	this->_Name = Name;
	this->_MaxHitPoints = 100;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "ScavTrap ";
	this->printStatus();
	std::cout << " has been put together!" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	this->printStatus();
	std::cout << " has all copied parts now." << std::endl;
	*this = src;
	return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs)
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

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap ";
	this->printStatus();
	std::cout << " has been thrown on the dump!" << std::endl;
	return;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0)
	{
		this->printStatus();
		std::cout << " auto-attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
		this->_EnergyPoints--;
	}
	else
	{
		this->printStatus();
		std::cout << " can't do his robotic attack " << target << " because it has no energy points left." << std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	this->printStatus();
	std::cout << " is now in Gate keeper mode." << std::endl;
}
