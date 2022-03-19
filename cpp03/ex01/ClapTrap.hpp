/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 14:06:49 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/14 14:06:49 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_CLAPTRAP_H
#define CPP03_CLAPTRAP_H

#define REDF "\x1b[31m"
#define GRNF "\x1b[32m"
#define RESET "\e[0m"

#include <string>

class ClapTrap
{
protected:
	std::string		_Name;
	unsigned int 	_MaxHitPoints;
	unsigned int	_HitPoints;
	unsigned int	_EnergyPoints;
	unsigned int	_AttackDamage;
	ClapTrap(void);

public:
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap const & src);
	ClapTrap& operator=(ClapTrap const & rhs);
	virtual ~ClapTrap(void);

	std::string 	getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void 			printStatus(void);
};

#endif //CPP03_CLAPTRAP_H
