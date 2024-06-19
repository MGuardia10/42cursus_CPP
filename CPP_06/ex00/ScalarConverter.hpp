#pragma once

#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>

enum	scalarType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

class	ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& other );
		~ScalarConverter();

	public:
		ScalarConverter& operator=( const ScalarConverter& other );
		static void convert( char *literal );
};