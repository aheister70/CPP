/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 19:41:10 by annaheister   #+#    #+#                 */
/*   Updated: 2022/03/07 10:13:35 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string replace(std::string contentIn, std::string s1, std::string s2)
{
    std::string contentReplaced;
	std::size_t found;
	std::size_t len_s1;

	len_s1 = s1.length();
	found = contentIn.find(s1);
	while (s1.length() > 0 && found != std::string::npos && s1.length())
	{
		contentIn.erase(found, len_s1);
		contentIn.insert(found, s2);
		found = contentIn.find(s1, found+(s2.length()));
	}
	contentReplaced = contentIn;
    return contentReplaced;
}

std::string fill_string(std::string file)
{
    std::ostringstream	buffer;
    std::string			contentIn;

    std::ifstream ifs(file, std::ifstream::binary);
    buffer << ifs.rdbuf();
    contentIn = buffer.str();
    ifs.close();
    return contentIn;
}

int main (int argc, char *argv[])
{
	std::string	contentIn;
	std::string	contentReplaced;
	std::string fileReplaced;

	if (argc < 4 || argc > 4)
	{
		std::cout << "Wrong amount of arguments" << std::endl;
		std::cout << "Input should be: file name, string_1, string_2" << std::endl;
		return 0;
	}
    contentIn = fill_string(argv[1]);
	contentReplaced = replace(contentIn, argv[2], argv[3]);
	fileReplaced = argv[1];
	fileReplaced += ".replaced";
    std::ofstream ofs(fileReplaced);
    ofs << contentReplaced;
    ofs.close();
	return 0;
}
