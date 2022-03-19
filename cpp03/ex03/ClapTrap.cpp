/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:39:29 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/16 13:39:29 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _MaxHitPoints(10), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "A default ClapTrap is born. " << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _MaxHitPoints(10), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap ";
	this->printStatus();
	std::cout << " is born!" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	this->printStatus();
	std::cout << " is copied." << std::endl;
	*this = src;
	return;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs)
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

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap ";
	this->printStatus();
	std::cout << " has died!" << std::endl;
	return;
}

std::string ClapTrap::getName(void) const
{
	return this->_Name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return this->_HitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return this->_EnergyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->_AttackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0)
	{
		this->printStatus();
		std::cout << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
		this->_EnergyPoints--;
	}
	else
	{
		this->printStatus();
		std::cout << " can't attack " << target << " because it has no energy points left." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoints == 0)
	{
		this->printStatus();
		std::cout << " can't take any damage, because it is already dead." << std::endl;
	}
	else
	{
		if (this->_HitPoints > amount)
			this->_HitPoints -= amount;
		else
			this->_HitPoints = 0;
		this->printStatus();
		std::cout << " has " << amount << " hit points damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints > 0 && amount > 0)
	{
		if (this->_HitPoints + amount > this->_MaxHitPoints)
			this->_HitPoints = this->_MaxHitPoints;
		else
			this->_HitPoints += amount;
		this->_EnergyPoints--;
		this->printStatus();
		std::cout << " repairs himself." << std::endl;
	}
	else if (this->_EnergyPoints == 0 && amount > 0)
	{
		this->printStatus();
		std::cout << " can't repair itself because it has no energy points left." << std::endl;
	}
	else
	{
		this->printStatus();
		std::cout << " doesn't need to repair itself because it has no attack damage." << std::endl;
	}
}

void ClapTrap::printStatus(void)
{
	std::cout << this->_Name << " [ " << GRNF << this->_HitPoints << " HP" RESET << " | ";
	std::cout << REDF << this->_EnergyPoints << " EP " RESET << "]";
}
