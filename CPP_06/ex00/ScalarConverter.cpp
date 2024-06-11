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
static inline bool isChar( std::string input ) {
	return (input.length() == 1 && !std::isdigit( static_cast<int>(input[0]) ));
}

static bool isInt( std::string input ) {
	try {
		std::size_t pos;
		long long number = std::stoll(input, &pos);
		static_cast<void>(number);
		return pos == input.length();
	} catch (std::out_of_range & e) {
		// gestionar valores fuera de rango
		std::cout << "outofrange\n";
		return false;
	} catch (std::invalid_argument&) {
		return false;
	}
}

static bool isFloat( std::string input ) {
	try {
        std::size_t pos;
        double number = std::stod(input, &pos);
		static_cast<void>(number);
		return (pos == input.length() - 1) && input.at(pos) == 'f';
    } catch (std::invalid_argument&) {
        return false;
    } catch (std::out_of_range&) {
        return false;
    }
}

static bool isDouble( std::string input ) {
	try {
        std::size_t pos;
        double number = std::stod(input, &pos);
		static_cast<void>(number);
		return pos == input.length();
    } catch (std::invalid_argument&) {
        return false;
    } catch (std::out_of_range&) {
        return false;
    }
}

void	print_char( double c ) {
	std::cout << "char: ";
	if (c >= 0 && c <= 255) {
		unsigned char cc = static_cast<unsigned char>( c );
		std::isprint( cc ) ? std::cout << '\'' << cc << "\'\n" : std::cout << "Non displayable.\n";
	} else
		std::cout << "impossible.\n";
}

void	ScalarConverter::convert( std::string input ) {

	if (isChar( input )) {
		std::cout << "char\n";
		print_char( static_cast<char>(input[0]) );
		// print_int();
		// print_float();
		// print_double();
	} else if (isInt( input )) {
		std::cout << "int\n";
		print_char( std::stoi( input ) );
		// int_case()
	} else if (isFloat( input )) {
		std::cout << "float\n";
		print_char( std::stof( input ) );
		// float_case();
	} else if (isDouble( input )) {
		std::cout << "double\n";
		print_char( std::stod( input ) );
		// double_case();
	} else
		std::cerr << "Impossible to convert\n";
}