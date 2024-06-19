#include "RPN.hpp"

/* static member definition */
std::stack<double> RPN::myStack;

/* OCCF */
RPN::RPN() {}
RPN::RPN( const RPN& other ) { *this = other; }
RPN& RPN::operator=( const RPN& other ) {
	if (this != &other)
		myStack = other.myStack;
	return *this;
}
RPN::~RPN() {}

/* calculate */
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
		} else if ( (op = std::strchr( "+-/*", *it )) != nullptr ) {

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
}

/* print result */
void RPN::printResult( void ) {
	if (myStack.size() == 1) {
		std::cout << myStack.top() << '\n';
		myStack.pop();
	} else
		throw RPN::wrongInputException();
}