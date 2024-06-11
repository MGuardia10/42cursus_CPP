#include "ScalarConverter.hpp"

#define RESET   "\033[0m"
#define RED 	"\e[1;91m"

int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << RED << "Please insert only one argument.\n" << RESET;
		return 1;
	}

	ScalarConverter::convert( argv[1] );

	return 0;
}