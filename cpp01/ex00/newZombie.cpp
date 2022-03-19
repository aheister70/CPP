/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:10:31 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/09 18:00:42 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	return new Zombie(name);
}
