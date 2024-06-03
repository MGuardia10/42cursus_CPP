#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		std::vector<int>	container;
		unsigned int 		maxSize;
		
		Span();

		class spanFullException : public std::exception {
			virtual const char* what() const throw() {
				return "cannot add more items, span is full";
			}
		};

		class notEnoughNumbersException : public std::exception {
			virtual const char* what() const throw() {
				return "span does not have enough numbers";
			}
		};

	public:
		Span( unsigned int N );
		Span( const Span& other );
		Span& operator=(const Span& other);
		~Span();

		int shortestSpan( void ) const;
		int longestSpan( void ) const;
		void addNumber( int nbr );

		template <typename T>
		void addManyNumbers(T it_begin, T it_end) {
			while (it_begin < it_end) {
				this->addNumber( *it_begin );
				it_begin++;
			}
		}
};