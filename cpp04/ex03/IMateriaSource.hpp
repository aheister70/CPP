/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IMateriaSource.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 08:50:25 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/23 08:50:25 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_IMATERIASOURCE_H
#define CPP04_IMATERIASOURCE_H

#include "AMateria.hpp"

class IMateriaSource {
public:
	virtual				~IMateriaSource(void) {}
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;
	virtual void		showMateria(void) = 0;
};

#endif //CPP04_IMATERIASOURCE_H
