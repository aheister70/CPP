/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Karen.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 11:10:03 by aheister      #+#    #+#                 */
/*   Updated: 2022/02/03 11:10:03 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP01_KAREN_H
#define CPP01_KAREN_H

#define PURF "\x1b[35m"
#define REDF "\x1b[31m"
#define RESET "\e[0m"

#include <string>

class Karen {
private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);

public:
	Karen(void);
	~Karen(void);

	void execute_function(void (Karen::*functionPtr)(void));
	void complain(std::string level);
};


#endif
