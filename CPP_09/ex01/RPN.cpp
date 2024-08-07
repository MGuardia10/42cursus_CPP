#include "RPN.hpp"

/* static member definition */
std::stack<double> RPN::myStack;

/* OCCF */
RPN::RPN() {}
RPN::RPN( const RPN& other ) { (void) other; }
RPN& RPN::operator=( const RPN& other ) {
	(void) other;
	return *this;
}
RPN::~RPN() {}

/* Exceptions */
const char* RPN::emptyStringException::what() const throw() {
	return "Error: The string is empty";
}

const char* RPN::wrongInputException::what() const throw() {
	return "Error: Wrong input";
}

/* calculate --> Supported operations: + , - , * , /  */
// supported operations: + , - , / , *
void RPN::calculate( std::string input ) {

	if (input.empty()) {
		throw RPN::emptyStringException();
	}

	std::string::iterator it = input.begin();
	std::string::iterator itEnd = input.end();

	while (it != itEnd) {

		const char *op = NULL;

		while (std::isspace( *it ))
			it++;
		if ( it == itEnd )
			break;
		
		if ( std::isdigit( *it ) ) {
			myStack.push( static_cast<double>( *it - '0' ) );
		} else if ( (op = std::strchr( "+-/*", *it )) != NULL ) {

			if (myStack.size() < 2)
				throw RPN::wrongInputException();
			
			double a = myStack.top();
			myStack.pop();
			double b = myStack.top();
			myStack.pop();

			switch ( static_cast<int>(*op) ) {
				case ADD:
					myStack.push( a + b );
					break;
				case SUBTRACT:
					myStack.push( b - a );
					break;
				case DIVIDE:
					myStack.push( b / a );
					break;
				case MULTIPLY:
					myStack.push( a * b );
					break;
				default:
					throw RPN::wrongInputException();
					break;
			}
		} else {
			throw RPN::wrongInputException();
		}

		it++;
	}

	if (myStack.size() == 1) {
		std::cout << myStack.top() << '\n';
		myStack.pop();
	} else {
		while (myStack.size() != 0) {
			myStack.pop();
		}

		throw RPN::wrongInputException();
	}

}
