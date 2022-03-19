/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClassContact.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 13:48:56 by aheister      #+#    #+#                 */
/*   Updated: 2022/01/20 13:48:56 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_H
#define CLASS_CONTACT_H

#define BLUB "\e[0;46m"
#define REDF "\x1b[31m"
#define GRNF "\x1b[32m"
#define RESET "\e[0m"

#include <string>

class Contact {

private:
	int			_idx;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	std::string	_adjust_format(std::string input);
	void		_set_values(int idx, std::string fN, std::string lN, std::string nN, std::string pN, std::string dS);

public:
	Contact(void);
	~Contact(void);

	int 		add_contact(int idx);
	std::string	get_input(std::string input);
	void		print_contact(void);
	void		print_contact_short(void);
};

#endif