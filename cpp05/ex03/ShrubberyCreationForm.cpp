/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:49:19 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/02 16:49:19 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("ShrubberyCreation", 145, 137, target) {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
		: AForm(src) {
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if(this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}

void ShrubberyCreationForm::execution(void) const {
	std::string targetFile;
	std::string shrub;

	shrub =
	"												\n"
	"			wWWWw               wWWWw			\n"
	"	vVVVv (___) wWWWw         (___)  vVVVv		\n"
	"	(___)  ~Y~  (___)  vVVVv   ~Y~   (___)		\n"
	"	~Y~   \\|    ~Y~   (___)    |/    ~Y~		\n"
	"	\\|   \\ |/   \\| /  \\~Y~/   \\|    \\ |/	\n"
	"	\\|// \\|// \\|/// \\|//  \\|// \\\\|///	\n"
	" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	\n";

	targetFile = this->getTarget() + "_shrubbery";
	std::ofstream ofs;
	ofs.open (targetFile, std::ofstream::out | std::ofstream::app);
	if (!ofs.is_open()) {
		std::cout << "Error: file " << targetFile << " could not be opened" << std::endl;
		return;
	}
	ofs << shrub;
	ofs.close();
}
