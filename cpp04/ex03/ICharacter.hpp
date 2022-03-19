/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ICharacter.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:22:38 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:22:38 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_ICHARACTER_H
# define CPP04_ICHARACTER_H

class AMateria;

# include "AMateria.hpp"
# include <string>

class ICharacter {
public:
	virtual ~ICharacter(void) {}
	virtual std::string const & getName(void) const = 0;
	virtual void equip(AMateria* materia) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif //CPP04_ICHARACTER_H
