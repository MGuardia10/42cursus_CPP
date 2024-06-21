#include "BitcoinExchange.hpp"

#define RESET		"\033[0m"
#define RED 		"\e[1;91m"
#define DATABASE	"./data.csv"

int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << RED << "Invalid number of arguments. Try: ./btc <db_file>" << RESET << '\n';
		return 1;
	}

	try {
		BitcoinExchange btc( DATABASE );
		btc.calculate( argv[1] );

	} catch ( std::exception& e ) {
		std::cout << RED << e.what() << RESET << '\n';
		return 1;
	}
	
	return 0;
}