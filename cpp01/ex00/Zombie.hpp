/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:10:51 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/09 17:59:52 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#define REDF "\x1b[31m"
#define GRNF "\x1b[32m"
#define RESET "\e[0m"

#include <string>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
