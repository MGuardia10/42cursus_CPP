#include "PmergeMe.hpp"
#define RED 	"\e[1;91m"
#define RESET   "\033[0m"

/* TODO
	- Parsing container OK
	- Print function OK
	- Print time function OK
	- exceptions and error management OK
	- OCCF
	- Merge-insertion sort algorithm
*/

int main( int argc, char **argv ) {

	if ( argc < 3 ) {
		std::cout << RED << "Error: Invalid number of arguments.\n" << RESET;
		return 1;
	}

	try {
		PmergeMe myContainers( argv );

		std::cout << "Before:	";
		myContainers.print();

		myContainers.sort();
		
		std::cout << "After:	";
		myContainers.print();

		myContainers.printTime();

	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << '\n' << RESET;
		return 1;
	}

	return 0;
}