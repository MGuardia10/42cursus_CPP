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
static void	intCase( int input ) {
	printChar( input );

	std::cout << "int: " << input << '\n';

	std::cout << "float: " << static_cast<float>( input );
	std::cout << (( input <= -1000000 || input >= 1000000 ) ? "\n" : ".0f\n");

	std::cout << "double: " << static_cast<double>( input );
	std::cout << (( input <= -1000000 || input >= 1000000 ) ? "\n" : ".0\n");
}

/* FLOAT and DOUBLE case */
static void	fractionalCase( double input, bool isNan ) {
	printChar( static_cast<int>( input ) );

	std::cout << "int: ";
	if ( input < static_cast<double>(INT_MIN) || input > static_cast<double>(INT_MAX) || isNan )
		std::cout << "impossible.\n";
	else
		std::cout << static_cast<int>( input ) << '\n';


	std::cout << "float: " << static_cast<float>(input);
	std::cout << ( ((floor(input) == input) && ( input > -1000000 && input < 1000000 )) ? ".0f\n" : "f\n" );

	std::cout << "double: " << input;
	std::cout << ( ((floor(input) == input) && ( input > -1000000 && input < 1000000 )) ? ".0\n" : "\n" );
}

static scalarType findType( char *input ) {
	int inputLength = strlen(input);
	/*
		CHAR conditions:
		- input length == 1.
		- character is not a digit.
	*/
	if (inputLength == 1 && !std::isdigit( static_cast<int>(input[0]) ))
		return CHAR;
	
	/*
		INT conditions:
		- inputEnd == NULL.
		- input length <= 11 -> max amount of numbers to fit in a INT type.
		- nbr must fit between INT_MIN & INT_MAX macros (otherwise it will be treated as a DOUBLE).
	*/
	char *inputEnd = NULL;
	long nbr = strtol(input, &inputEnd, 10);

	if (!inputEnd[0] && inputLength <= 11 && nbr >= INT_MIN && nbr <= INT_MAX)
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
			charCase( static_cast<char>(input[0]) );
			break;
		case INT:
			intCase( atoi( input ) );
			break;
		case FLOAT:
			bool isNanF;
			(strcmp(input, "+nanf") == 0 || strcmp(input, "-nanf") == 0 || strcmp(input, "nanf") == 0) ? isNanF = true : isNanF = false;
			/* atof returns a double, if I cast to float I´ll miss precision in some cases so better work with doubles here */
			fractionalCase( atof( input ), isNanF );
			break;
		case DOUBLE:
			bool isNan;
			(strcmp(input, "+nan") == 0 || strcmp(input, "-nan") == 0 || strcmp(input, "nan") == 0) ? isNan = true : isNan = false;
			fractionalCase( atof( input ), isNan );
			break;
		default:
			std::cerr << "impossible to convert\n";
			break;
	}
}
