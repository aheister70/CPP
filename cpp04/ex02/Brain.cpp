/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:15:45 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/21 17:15:45 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Creation of a brain." << std::endl;
	return;
}

Brain::Brain(Brain const & src) {
	*this = src;
	std::cout << "A brain is copied" << std::endl;
	return;
}

Brain& Brain::operator=(Brain const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Destroy of brain." << std::endl;
	return;
}

void Brain::setIdea(std::string Idea, int i) {
	this->_ideas[i] = Idea;
}

std::string Brain::getIdea(int i) {
	return this->_ideas[i];
}
