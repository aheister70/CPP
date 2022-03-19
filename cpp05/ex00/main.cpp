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
#include <iostream>

int main(void) {
	std::cout << GRNF "\nFirst we create bureaucrat 'Alex' with grade -1" RESET << std::endl;
	Bureaucrat* tooHigh = new Bureaucrat("Alex", -1);
	std::cout << GRNF "If the grade is invalid, the bureaugrat gets the default grade of 150" RESET << std::endl;
	std::cout << *tooHigh << std::endl;
	std::cout << GRNF "\nThen we create bureaucrat 'Flip' with grade 151" RESET << std::endl;
	Bureaucrat* tooLow = new Bureaucrat("Flip", 151);
	std::cout << *tooLow << std::endl;
	std::cout << GRNF "\nWe try to lower Flips grade using the decrement function" RESET << std::endl;
	tooLow->decrementGrade();
	std::cout << GRNF "Obviously that didn't work ;-)" RESET << std::endl;

	std::cout << GRNF "\nNow we create bureaucrat 'Highy' with grade 10" RESET << std::endl;
	Bureaucrat* High = new Bureaucrat("Highy", 10);
	std::cout << *High << std::endl;
	std::cout << GRNF "We decrement Highy's grade using the decrement function" RESET << std::endl;
	High->decrementGrade();
	std::cout << *High << std::endl;

	std::cout << GRNF "\nAt last we create bureaucrat 'Lowie' with grade 140" RESET << std::endl;
	Bureaucrat* Low = new Bureaucrat("Lowie", 140);
	std::cout << *Low << std::endl;
	std::cout << GRNF "We increment Highy's grade using the increment function" RESET << std::endl;
	Low->incrementGrade();
	std::cout << *Low << std::endl;

	delete tooHigh;
	delete tooLow;
	delete High;
	delete Low;
	//system ("leaks bureaucrat");
	return 0;
}
