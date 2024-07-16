#include "Span.hpp"

/* OCCF */
Span::Span(): maxSize(0) {}
Span::Span( unsigned int N ): maxSize(N) {}

Span::Span( const Span& other ) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->container = other.container;
		this->maxSize = other.maxSize;
	}

	return *this;
}

Span::~Span() {}

/* Exceptions */
const char* Span::spanFullException::what() const throw() {
	return "cannot add more items, span is full";
}

const char* Span::notEnoughNumbersException::what() const throw() {
	return "span does not have enough numbers";
}

/* Public methods */
int Span::shortestSpan( void ) const {
	if ( container.size() == 0 || container.size() == 1 )
		throw Span::notEnoughNumbersException();

	int result = INT_MAX;
	std::vector<int>::const_iterator it_begin = container.begin();
	while (it_begin < container.end()) {
		std::vector<int>::const_iterator it_next = it_begin + 1;
		while (it_next < container.end()) {
			int span = std::max( *it_begin, *it_next ) - std::min(*it_begin, *it_next);
			if (span < result)
				result = span;
			it_next++;
		}
		it_begin++;
	}

	return result;
}

int Span::longestSpan( void ) const {
	if ( container.size() == 0 || container.size() == 1 )
		throw Span::notEnoughNumbersException();

	int result = 0;
	std::vector<int>::const_iterator it_begin = container.begin();
	while (it_begin < container.end()) {
		std::vector<int>::const_iterator it_next = it_begin + 1;
		while (it_next < container.end()) {
			int span = std::max( *it_begin, *it_next ) - std::min(*it_begin, *it_next);
			if (span > result)
				result = span;
			it_next++;
		}
		it_begin++;
	}

	return result;
}

void Span::addNumber( int nbr ) {
	if ( container.size() == this->maxSize )
		throw Span::spanFullException();
	
	container.push_back( nbr );
}
