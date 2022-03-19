/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:17:32 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:17:32 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_AMATERIA_H
#define CPP04_AMATERIA_H

class ICharacter;
#include "ICharacter.hpp"
#include <string>

/*
 * AMateria is the abstract base class for all materia (like Ice and Cure).
 * An abstract class contains one or more pure virtual functions. It's not
 * possible to create objects from an abstract class.
 */

class AMateria {
protected:
	std::string type;

	AMateria(void);

public:
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	AMateria& operator=(AMateria const & rhs);
	virtual ~AMateria(void);

	std::string const & getType(void) const;
	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);
};

#endif //CPP04_AMATERIA_H
