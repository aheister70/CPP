/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:47:28 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/22 12:47:28 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_ICE_H
#define CPP04_ICE_H

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(std::string const & type);
	Ice(Ice const & src);
	Ice& operator=(Ice const & rhs);
	virtual ~Ice(void);

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);
};


#endif //CPP04_ICE_H
