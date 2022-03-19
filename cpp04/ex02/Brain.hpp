/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:16:00 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:16:00 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_BRAIN_H
#define CPP04_BRAIN_H

#include <string>

class Brain {
private:
	std::string _ideas[100];

public:
	Brain(void);
	Brain(Brain const & src);
	Brain& operator=(Brain const & rhs);
	virtual ~Brain(void);

	void setIdea(std::string Idea, int i);
	std::string getIdea(int i);
};


#endif //CPP04_BRAIN_H
