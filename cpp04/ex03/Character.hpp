/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 08:38:31 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/23 08:38:31 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_CHARACTER_H
#define CPP04_CHARACTER_H

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
	std::string _name;
	int 		_amount;
	AMateria*	_inventory[4];
	AMateria*	_lostInventory;

public:
	Character(void);
	Character(std::string name);
	Character(Character const & src);
	Character& operator=(Character & rhs);
	virtual ~Character(void);

	virtual std::string const & getName(void) const;
	virtual void equip(AMateria* materia);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif //CPP04_CHARACTER_H
