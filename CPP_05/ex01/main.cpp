#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void ) {
	{
		/* OCCF & << overload operator tests */
		Form a;
		Form b("Helsinki");
		Form c("Madrid", 87);
		Form d("Paris", 76, 42);
		Form e( b );
		Form f;
		f = c;

		std::cout << "\na adress: " << &a << "\na content: " << a << "\n\n";
		std::cout << "b adress: " << &b << "\nb content: " << b << "\n\n";
		std::cout << "c adress: " << &c << "\nc content: " << c << "\n\n";
		std::cout << "d adress: " << &d << "\nd content: " << d << "\n\n";
		std::cout << "e adress: " << &e << "\ne content: " << e << "\n\n";
		std::cout << "f adress: " << &f << "\nf content: " << f << "\n\n"; // constants dont change

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Form Exceptions tests */
		try {
			Form a("Madrid", 0);
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Form a("Madrid", 151);
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Form a("Madrid", 15, 0);
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Form a("Madrid", 15, 151);
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Bureaucrat a("Pepe", 141);
			Form b("Madrid", 140);

			a.signForm( b );
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Bureaucrat a("Pepe", 141);
			Form b("Madrid", 141);

			a.signForm( b );
			a.signForm( b );
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Normal cases */
		try {
			Bureaucrat a("Miguel", 141);
			Form b("Madrid", 142, 16);

			std::cout << a << '\n';
			std::cout << b << "\n\n";

			a.signForm( b );

			std::cout << a << '\n';
			std::cout << b << "\n\n";
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}

		try {
			Bureaucrat a("Miguel", 141);
			Form b("Madrid", 142, 16);

			std::cout << a << '\n';
			std::cout << b << "\n\n";

			b.beSigned( a );

			std::cout << a << '\n';
			std::cout << b << "\n\n";
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}
	}

}