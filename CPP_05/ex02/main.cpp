#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* TODO 
	- testear OCCF, executeForm de burocrata, execute AForm, 
	- ShrubberyCreationForm -> Required grades: 
	- RobotomyRequestForm -> Required grades: sign 72, exec 45
	- PresidentialPardonForm ->  Required grades: sign 25, exec 5
	- En bureaucrat -> void executeForm(AForm const & form);
*/

int	main( void ) {
	{
		/* Abstract Class test */

		// AForm abstractTest;
	}
	{
		/* ShrubberyCreationForm tests -> sign 145, exec 137 */

		ShrubberyCreationForm a;
		ShrubberyCreationForm b( "Home" );
		ShrubberyCreationForm c( b );
		ShrubberyCreationForm d;
		d = a;
		
		std::cout << "\na adress: " << &a << "\na content: " << a << "\n\n";
		std::cout << "b adress: " << &b << "\nb content: " << b << "\n\n";
		std::cout << "c adress: " << &c << "\nc content: " << c << "\n\n";
		std::cout << "d adress: " << &d << "\nd content: " << d << "\n\n";

		try {
			Bureaucrat employerA("Miguel", 1);
			Bureaucrat employerB("Manuel", 136);

			// employerA signs and employerB executes OK
			employerA.signForm( a );
			employerB.executeForm( a );

			employerB.decrementGrade();	// now employerB grade = 137

			// employerA signs and employerB executes OK
			employerA.signForm( b );
			employerB.executeForm( b );

			employerB.decrementGrade();	// now employerB grade = 138

			// employerA signs and employerB cannot execute the form because of his grade
			employerA.signForm( c );
			employerB.executeForm( c );

			// employerB cannot execute form because is not signed
			employerB.executeForm( d );

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* RobotomyRequestForm tests -> sign 72, exec 45 */

		RobotomyRequestForm a;
		RobotomyRequestForm b( "Home" );
		RobotomyRequestForm c( b );
		RobotomyRequestForm d;
		d = a;
		
		std::cout << "\na adress: " << &a << "\na content: " << a << "\n\n";
		std::cout << "b adress: " << &b << "\nb content: " << b << "\n\n";
		std::cout << "c adress: " << &c << "\nc content: " << c << "\n\n";
		std::cout << "d adress: " << &d << "\nd content: " << d << "\n\n";

		try {
			Bureaucrat employerA("Miguel", 1);
			Bureaucrat employerB("Manuel", 44);

			// employerA signs and employerB executes OK
			employerA.signForm( a );
			employerB.executeForm( a );

			employerB.decrementGrade();	// now employerB grade = 137

			// employerA signs and employerB executes OK
			employerA.signForm( b );
			employerB.executeForm( b );

			employerB.decrementGrade();	// now employerB grade = 138

			// employerA signs and employerB cannot execute the form because of his grade
			employerA.signForm( c );
			employerB.executeForm( c );

			// employerB cannot execute form because is not signed
			employerB.executeForm( d );

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}	
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* RobotomyRequestForm tests -> sign 25, exec 5 */

		PresidentialPardonForm a;
		PresidentialPardonForm b( "Home" );
		PresidentialPardonForm c( b );
		PresidentialPardonForm d;
		d = a;
		
		std::cout << "\na adress: " << &a << "\na content: " << a << "\n\n";
		std::cout << "b adress: " << &b << "\nb content: " << b << "\n\n";
		std::cout << "c adress: " << &c << "\nc content: " << c << "\n\n";
		std::cout << "d adress: " << &d << "\nd content: " << d << "\n\n";

		try {
			Bureaucrat employerA("Miguel", 1);
			Bureaucrat employerB("Manuel", 4);

			// employerA signs and employerB executes OK
			employerA.signForm( a );
			employerB.executeForm( a );

			employerB.decrementGrade();	// now employerB grade = 

			// employerA signs and employerB executes OK
			employerA.signForm( b );
			employerB.executeForm( b );

			employerB.decrementGrade();	// now employerB grade = 138

			// employerA signs and employerB cannot execute the form because of his grade
			employerA.signForm( c );
			employerB.executeForm( c );

			// employerB cannot execute form because is not signed
			employerB.executeForm( d );

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}
}