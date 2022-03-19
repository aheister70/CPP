/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 09:26:22 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/23 09:26:22 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_MATERIASOURCE_H
#define CPP04_MATERIASOURCE_H

#include "IMateriaSource.hpp"

/*
 * The MateriaSource is the base in which a template of a new Materia can be stored
 * (by the function learn) and from which the Materia can be created to be used to equip
 * a character (to put this materia in his inventory).
 */

class MateriaSource : public IMateriaSource {
private:
	int 		_amount;
	AMateria* 	_materias[4];

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	MateriaSource& operator=(MateriaSource const & rhs);
	virtual ~MateriaSource(void);

	virtual	void		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const & type);
	virtual void		showMateria(void);
};

#endif //CPP04_MATERIASOURCE_H
