#include "iter.hpp"

template <typename T>
void	printArray( T& item ) {
	std::cout << item << '\n';
}

template <typename T>
void	do_square( T& nbr ) {
	nbr *= nbr;
}

void	to_upper( char& c ) {
		c = std::toupper( c );
}

int main( void ) {
	{
		int Array[] = { 1, 2, 3, 4, 5 };
		size_t length = sizeof(Array) / sizeof(Array[0]);

		std::cout << "Original array:\n";
    	iter( Array, length, printArray<int> );

		iter( Array, length, do_square<int> );
    	
	    std::cout << "Array after do_square:\n";
		iter(Array, length, printArray<int>);
	}
	std::cout << "----------------------------------------------------\n";
	{
		float Array[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
		size_t length = sizeof(Array) / sizeof(Array[0]);

		std::cout << "Original array:\n";
    	iter( Array, length, printArray<float> );

		iter( Array, length, do_square<float> );
    	
	    std::cout << "Array after do_square:\n";
		iter(Array, length, printArray<float>);

	}
	std::cout << "----------------------------------------------------\n";
	{
		double Array[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
		size_t length = sizeof(Array) / sizeof(Array[0]);

		std::cout << "Original array:\n";
    	iter( Array, length, printArray<double> );

		iter( Array, length, do_square<double> );
    	
	    std::cout << "Array after do_square:\n";
		iter(Array, length, printArray<double>);
		
	}
	std::cout << "----------------------------------------------------\n";
	{
		char Array[] = { 'h', 'o', 'l', 'a', '.' };
		size_t length = sizeof(Array) / sizeof(Array[0]);

		std::cout << "Original array:\n";
    	iter( Array, length, printArray<char> );

		iter( Array, length, to_upper );
    	
	    std::cout << "Array after to_upper:\n";
		iter(Array, length, printArray<char>);
	}
	
	return 0;
}