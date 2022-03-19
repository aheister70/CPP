/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:47:10 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:47:10 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_CURE_H
#define CPP04_CURE_H

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(std::string const & type);
	Cure(Cure const & src);
	Cure& operator=(Cure const & rhs);
	virtual ~Cure(void);

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);
};


#endif //CPP04_CURE_H
