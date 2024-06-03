#include "Span.hpp"

int main( void ) {
	{
		/* Subject tests */
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* Adding more numbers */
		try {
			Span sp = Span(7);
			int arr[] = { 11, 20, 300, -5, 14, 16, 22 };

			sp.addManyNumbers( arr, arr + sizeof(arr) / sizeof(arr[0]) );

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* Error management */
		try {
			Span sp = Span(5);
			int arr[] = { 11, 20, 300, -5, 14, 16, 22 };

			sp.addManyNumbers( arr, arr + sizeof(arr) / sizeof(arr[0]) );

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* Error management */
		try {
			Span sp = Span(1);

			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	return 0;
}