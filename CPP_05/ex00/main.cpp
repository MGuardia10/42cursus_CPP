#include "Bureaucrat.hpp"

int	main( void ) {
	{
		/* OCCF & << overload operator tests */
		Bureaucrat a;
		Bureaucrat b("Pepe");
		Bureaucrat c("Juan", 87);
		Bureaucrat d( a );
		Bureaucrat e;
		e = c;

		std::cout << "\na adress: " << &a << "\na content: " << a << "\n\n";
		std::cout << "b adress: " << &b << "\nb content: " << b << "\n\n";
		std::cout << "c adress: " << &c << "\nc content: " << c << "\n\n";
		std::cout << "d adress: " << &d << "\nd content: " << d << "\n\n";
		std::cout << "e adress: " << &e << "\ne content: " << e << "\n\n"; // Name dont change bc is constant

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Exception tests */
		try {
			Bureaucrat a("Miguel", 0);
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Bureaucrat a("Manuel", 151);
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Bureaucrat a("Daniel", -16);
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Bureaucrat a("Juan", 10);

			for (int i = 0; i < 10; i++) {
				a.incrementGrade();
			}
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Bureaucrat a("Pepe", 141);

			for (int i = 0; i < 10; i++) {
				a.decrementGrade();
			}
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Normal cases */
		try {
			Bureaucrat a("Miguel", 10);
			Bureaucrat b("Manuel", 36);

			std::cout << a << '\n';
			std::cout << b << "\n\n";

			a.decrementGrade();
			b.incrementGrade();

			std::cout << a << '\n';
			std::cout << b << "\n\n";
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}
	}

}