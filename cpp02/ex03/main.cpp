/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:18:21 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/11 10:18:21 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point const		a(0, 0);
	Point const		b(4, 4);
	Point const		c(8, 0);
	Point const		point(4, 3);
	int inside;

	inside = bsp(a, b, c, point);
	if (inside == true)
		std::cout << "The point lies inside" << std::endl;
	else
		std::cout << "The point lies outside" << std::endl;
	return 0;
}
