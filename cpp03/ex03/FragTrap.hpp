/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:46:21 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/16 13:46:21 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_FRAGTRAP_H
#define CPP03_FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap(void);

public:
	FragTrap(std::string Name);
	FragTrap(FragTrap const & src);
	FragTrap& operator=(FragTrap const & rhs);
	virtual ~FragTrap(void);

	void	attack(const std::string& target);
	void	highFivesGuys(void);
};

#endif //CPP03_FRAGTRAP_H
