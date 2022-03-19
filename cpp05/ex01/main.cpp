/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 08:17:42 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/01 08:17:42 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
	std::cout << GRNF "We create bureaucrat 'Highy' with grade 35" RESET << std::endl;
	Bureaucrat* High = new Bureaucrat("Highy", 35);
	std::cout << *High << std::endl;
	std::cout << GRNF "And we create bureaucrat 'Lowie' with grade 140" RESET << std::endl;
	Bureaucrat* Low = new Bureaucrat("Lowie", 140);
	std::cout << *Low << std::endl;

	std::cout << GRNF "\nWe create a form 'Apply for Work' with invalid signGrade 151 and executionGrade -1" RESET << std::endl;
	Form* ApplyCourse1 = new Form("Apply for course", 151, -1);
	delete ApplyCourse1;
	std::cout << GRNF "We create a another form 'Apply for Work' with signGrade 35 and executionGrade 15" RESET << std::endl;
	Form* ApplyCourse2 = new Form("Apply for course", 35, 15);
	std::cout << *ApplyCourse2 << std::endl;

	std::cout << GRNF "\nBureaucrat 'Lowie' wants to sign the form 'Apply for Course'" RESET << std::endl;
	Low->signForm(*ApplyCourse2);
	std::cout << GRNF "\nBureaucrat 'Highy' wants to sign the form 'Apply for Course'" RESET << std::endl;
	High->signForm(*ApplyCourse2);
	std::cout << GRNF "The form 'Apply for Course' is signed now" RESET << std::endl;
	std::cout << *ApplyCourse2 << std::endl;
	std::cout << GRNF "\nBureaucrat 'Highy' tries to sign the form 'Apply for Course' again" RESET << std::endl;
	High->signForm(*ApplyCourse2);

	delete High;
	delete Low;
	delete ApplyCourse2;
//	system ("leaks bureaucrat");
	return 0;
}
