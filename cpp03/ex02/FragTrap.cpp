/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:46:33 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/16 13:46:33 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string Name)
{
	this->_Name = Name;
	this->_MaxHitPoints = 100;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap ";
	this->printStatus();
	std::cout << " has been created beautifully!" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & src)
{
	this->printStatus();
	std::cout << " has been beautifully copied." << std::endl;
	*this = src;
	return;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs)
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

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap ";
	this->printStatus();
	std::cout << " just died gracefully like the swan in swan lake!" << std::endl;
	return;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0)
	{
		this->printStatus();
		std::cout << " makes a pirouette and attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
		this->_EnergyPoints--;
	}
	else
	{
		this->printStatus();
		std::cout << " can't do his graceful attack " << target << " because it has no energy points left." << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	this->printStatus();
	std::cout << " says: \' Give me a high five, you beautiful people\'!" << std::endl;
}
