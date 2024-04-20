#include "apb.h"
#include "PhoneBook.hpp"

int main(void)
{	
	std::string	input;
	PhoneBook	book;

	std::cout << std::endl;
	std::cout << BG << " Welcome to MyAwesomePhoneBook! 📞 " << RESET << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::cout << "Type a command (";
		std::cout << GREEN << "ADD" << RESET << ", ";
		std::cout << BLUE << "SEARCH" << RESET << " or ";
		std::cout << RED << "EXIT" << RESET << "): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << RED << "\nCtrl + D signal. Exiting..." << RESET << std::endl;
			return 1;
		}
		if (input.compare("ADD") == 0)
			book.add();
		else if (input.compare("SEARCH") == 0)
			book.search();
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	std::cout << CYAN << "Bye 👋" << RESET << std::endl;
	return 0;
}
