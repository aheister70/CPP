/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:25:35 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/01 16:25:35 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon(void);

	void				setType(std::string type);
	const std::string & getType(void);
};

#endif
