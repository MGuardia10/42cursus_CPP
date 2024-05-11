#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Increment / Decrement operators */
		Fixed a;
		Fixed b;

		std::cout << "a: " << a << std::endl;
		std::cout << "++a: " << ++a << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "a++: " << a++ << std::endl;
		std::cout << "a value: " << a << std::endl << std::endl;

		std::cout << "b: " << b << std::endl;
		std::cout << "--b: " << --b << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "b--: " << b-- << std::endl;
		std::cout << "b value: " << b << std::endl << std::endl;

		std::cout << "max: " << Fixed::max( a, b ) << std::endl;
		std::cout << "min: " << Fixed::min( a, b ) << std::endl << std::endl;
		

		
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Comparison and Artihmetic operators */
		Fixed a( Fixed(20.5f) / Fixed(2) );
		Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

		/* Different values */
		std::cout << "case 1: Different values:" << std::endl;
		std::cout << "a value: " << a << std::endl;
		std::cout << "b value: " << b << std::endl << std::endl;

		if ( a != b )
			std::cout << "a and c are different" << std::endl;
		if ( a == b )
			std::cout << "a and c are equal" << std::endl;
		if ( a > b )
			std::cout << "a is bigger than b" << std::endl;
		if ( a < b )
			std::cout << "a is smaller than b" << std::endl;
		if ( a >= b )
			std::cout << "a is bigger or equal to b" << std::endl;
		if ( a <= b )
			std::cout << "a is smaller or equal to b" << std::endl;

		/* Same values */
		std::cout << "\ncase 2: Same values:" << std::endl;

		a = b;

		std::cout << "a value: " << a << std::endl;
		std::cout << "b value: " << b << std::endl << std::endl;

		if ( a != b )
			std::cout << "a and c are different" << std::endl;
		if ( a == b )
			std::cout << "a and c are equal" << std::endl;
		if ( a > b )
			std::cout << "a is bigger than b" << std::endl;
		if ( a < b )
			std::cout << "a is smaller than b" << std::endl;
		if ( a >= b )
			std::cout << "a is bigger or equal to b" << std::endl;
		if ( a <= b )
			std::cout << "a is smaller or equal to b" << std::endl;
		
	}

	return 0;
}