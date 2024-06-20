#include "RPN.hpp"

#define RESET   "\033[0m"
#define RED 	"\e[1;91m"

int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << RED << "Invalid number of arguments" << RESET << '\n';
		return 1;
	}

	try {
		RPN::calculate( argv[1] );

	} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << '\n';
		return 1;
	}

	return 0;
}