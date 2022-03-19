/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Karen.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:45:00 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/05 18:45:00 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

Karen::Karen(void)
{
	return;
}
Karen::~Karen(void)
{
	return;
}

void Karen::_debug(void)
{
	std::cout << PURF "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. " << std::endl;
	std::cout << "I just love it!" RESET << std::endl;
}
void Karen::_info(void)
{
	std::cout << PURF "I cannot believe adding extra bacon costs more money. You don't put enough! " << std::endl;
	std::cout << "If you did I would not have to ask for it!" RESET << std::endl;
}
void Karen::_warning(void)
{
	std::cout << PURF "I think I deserve to have some extra bacon for free. " << std::endl;
	std::cout << "I've coming here for years and you just started working here last month." RESET << std::endl;
}
void Karen::_error(void)
{
	std::cout << PURF "This is unacceptable, I want to speak the manager now." RESET << std::endl;
}

void Karen::complain(std::string level)
{
	int idx;
	void (Karen::*ptr[])() = { &Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error};
	std::string complaint[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	idx = 0;
	while (level.compare(complaint[idx]) != 0)
		idx++;
	(this->*ptr[idx])();
}