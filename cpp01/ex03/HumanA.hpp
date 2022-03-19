/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:23:05 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/01 16:23:05 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	HumanA(std::string name, Weapon& club);
	~HumanA(void);

	void attack(void);

};

#endif
