/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:25:28 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/01 16:25:28 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string & Weapon::getType(void)
{
	return this->_type;
}
