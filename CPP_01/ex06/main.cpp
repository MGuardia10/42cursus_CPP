#include "Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << RED << "Error: invalid arguments. Only one argument is required." << RESET << std::endl;
		return 1;
	}

	Harl alvaro;
	alvaro.complain( argv[1] );
	
	return 0;
}