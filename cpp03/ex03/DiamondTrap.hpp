/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 15:52:26 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/19 15:52:26 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_DIAMONDTRAP_H
#define CPP03_DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string 	_Name;
	DiamondTrap(void);

public:
	DiamondTrap(std::string Name);
	DiamondTrap(DiamondTrap const & src);
	DiamondTrap& operator=(DiamondTrap const & rhs);
	virtual ~DiamondTrap(void);

	void attack(const std::string& target);
	void whoAmI(void);
};

#endif //CPP03_DIAMONDTRAP_H
