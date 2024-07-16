#pragma once

#include <iostream>
#include <stack>
#include <cstring>

#define ADD			43
#define SUBTRACT	45
#define MULTIPLY	42
#define DIVIDE		47


class RPN {
	private:
		/* Stack container */
		static std::stack<double> myStack;

		/* OCCF */
		RPN();
		RPN( const RPN& other );
		~RPN();

		/* Exceptions */
		class emptyStringException : public std::exception {
			const char* what() const throw();
		};

		class wrongInputException : public std::exception {
			const char* what() const throw();
		};

	public:
		RPN& operator=( const RPN& other );

		/* public methods */
		static void calculate( std::string input );
};