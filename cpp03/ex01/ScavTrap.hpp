/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 14:09:38 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/14 14:09:38 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_SCAVTRAP_H
#define CPP03_SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap(void);

public:
	ScavTrap(std::string Name);
	ScavTrap(ScavTrap const & src);
	ScavTrap& operator=(ScavTrap const & rhs);
	virtual ~ScavTrap(void);

	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif //CPP03_SCAVTRAP_H
