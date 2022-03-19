/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClassPhonebook.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:03:16 by aheister      #+#    #+#                 */
/*   Updated: 2022/01/20 15:03:16 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_H
#define CLASS_PHONEBOOK_H

#include "ClassContact.hpp"

class Phonebook {

private:
	int 		_full;
	Contact		_contacts[8];

public:
	Phonebook(void);
	~Phonebook(void);

	int 	add_contacts(int idx);
	void	input_command(void);
	void	search_contacts(int nb);
};

#endif