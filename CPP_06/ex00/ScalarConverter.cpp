#include "ScalarConverter.hpp"

/* OCCF */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter( const ScalarConverter& other ) { (void) other; }
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other ) { 
	(void) other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

/* converter */

static void	printChar( int c ) {
	std::cout << "char: ";
	if (c >= CHAR_MIN && c <= CHAR_MAX) {
		std::isprint( c ) ? std::cout << '\'' << static_cast<char>( c ) << "\'\n" : std::cout << "Non displayable.\n";
	} else {
		std::cout << "impossible.\n";
	}
}

/* CHAR case */
static void	charCase( char input ) {
	printChar( static_cast<int>(input) );
	std::cout << "int: " << static_cast<int>( input ) << '\n';
	std::cout << "float: " << static_cast<float>( input ) << ".0f\n";
	std::cout << "double: " << static_cast<double>( input ) << ".0\n";

}

/* INT case */
// static void	intCase(  ) {
	
// }

/* FLOAT case */
// static void	floatCase(  ) {
	
// }

/* DOUBLE case */
// static void	doubleCase(  ) {
	
// }

static scalarType findType( char *input ) {
	/*
		CHAR conditions:
		- input length == 1.
		- character is not a digit.
	*/
	if (strlen(input) == 1 && !std::isdigit( static_cast<int>(input[0]) ))
		return CHAR;
	
	/*
		INT conditions:
		- inputEnd == NULL.
		- input length <= 11 -> max amount of numbers to fit in a INT type.
		- nbr must fit between INT_MIN & INT_MAX macros.
	*/
	char *inputEnd = NULL;
	long nbr = strtol(input, &inputEnd, 10);

	if (!inputEnd[0] && (strlen(input) <= 11) && nbr >= INT_MIN && nbr <= INT_MAX)
		return INT;

	/*
		DOUBLE conditions:
		- inputEnd == NULL.

		FLOAT conditions:
		- inputEnd == "f".
	*/
	inputEnd = NULL;
	strtod(input, &inputEnd);

	if (!inputEnd[0])
		return DOUBLE;
	if (strcmp(inputEnd, "f") == 0)
		return FLOAT;

	return ERROR;
}

void	ScalarConverter::convert( char *input ) {

	switch (findType( input )) {
		case CHAR:
			std::cout << "char\n";
			charCase(static_cast<char>(input[0]));
			break;
		case INT:
			std::cout << "int\n";
			// intCase();
			break;
		case FLOAT:
			std::cout << "float\n";
			// floatCase();
			break;
		case DOUBLE:
			std::cout << "double\n";
			// doubleCase();
			break;
		default:
			std::cerr << "impossible to convert" << std::endl;
			break;
	}
}