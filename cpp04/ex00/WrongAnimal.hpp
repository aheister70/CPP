/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 10:18:11 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 10:18:11 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_WRONGANIMAL_H
#define CPP04_WRONGANIMAL_H

#include <string>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	WrongAnimal& operator=(WrongAnimal const & rhs);
	virtual ~WrongAnimal(void);

	std::string 	getType(void) const;
	void			makeSound(void) const;
};

#endif //CPP04_WRONGANIMAL_H
