#include "Intern.hpp"

int	main( void ) {
	/* evitar en Robotomy Request que se genere la misma secuencia siempre */
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	{
		/* Shrubbery creation form test */
		try {
			Intern internA;
			Bureaucrat bureaucratA( "Pepe", 1 );
			AForm* FormA = internA.makeForm( "shrubbery creation", "home" );

			std::cout << '\n' << *FormA << '\n';

			bureaucratA.signForm( *FormA );
			bureaucratA.executeForm( *FormA );

			delete FormA;

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Robotomy request form test */
		try {
			Intern internA;
			Bureaucrat bureaucratA( "Manuel", 1 );
			AForm* FormA = internA.makeForm( "ROBOTOMY REQUEST", "home" );

			std::cout << '\n' << *FormA << '\n';

			bureaucratA.signForm( *FormA );
			for (int i = 0; i < 5; i++)
				bureaucratA.executeForm( *FormA );
			
			delete FormA;

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
		
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Presidential pardon form test */
		try {
			Intern internA;
			Bureaucrat bureaucratA( "Manuel", 1 );
			AForm* FormA = internA.makeForm( "PreSIdential pArDon", "home" );

			std::cout << '\n' << *FormA << '\n';

			bureaucratA.signForm( *FormA );
			bureaucratA.executeForm( *FormA );

			delete FormA;

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}	
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Error management */

		// no target specified
		try {
			Intern internA;
			Bureaucrat bureaucratA( "Manuel", 1 );
			AForm* FormA = internA.makeForm( "presidential pardon", "" );

			std::cout << '\n' << *FormA << '\n';

			bureaucratA.signForm( *FormA );
			bureaucratA.executeForm( *FormA );

			delete FormA;

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}

		// form not found
		try {
			Intern internA;
			Bureaucrat bureaucratA( "Manuel", 1 );
			AForm* FormA = internA.makeForm( "form not found", "home" );

			std::cout << '\n' << *FormA << '\n';

			bureaucratA.signForm( *FormA );
			bureaucratA.executeForm( *FormA );

			delete FormA;

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}
}