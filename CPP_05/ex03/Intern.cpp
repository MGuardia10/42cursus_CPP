#include "Intern.hpp"

/* OCCF */
Intern::Intern() {}

Intern::Intern( const Intern& other ) { *this = other; }

Intern& Intern::operator=( const Intern& other ) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

/* Exceptions */
const char* Intern::NoTargetSpecifiedExcepcion::what() const throw() {
	return "the target of the form is empty";
}

const char* Intern::FormNotFoundExcepcion::what() const throw() {
	return "Intern cannot find the proper form";
}

/* Make forms */
AForm* Intern::makeSCF( std::string& target) {
	return (new ShrubberyCreationForm( target ));
}

AForm* Intern::makeRRF( std::string& target) {
	return (new RobotomyRequestForm( target ));
}

AForm* Intern::makePPF( std::string& target) {
	return (new PresidentialPardonForm( target ));
}


/* Public Methods */
AForm* Intern::makeForm( std::string name, std::string target ) {

	if (target.empty())
		throw Intern::NoTargetSpecifiedExcepcion();

	AForm* (Intern::*function[3])( std::string& target ) = { &Intern::makeSCF, &Intern::makeRRF, &Intern::makePPF };
	std::string stringArr[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	int i = 0;
	while (name[i]) {
		name[i] = std::tolower(name[i]);
		i++;
	}

	for (int j = 0; j < 3; j++) {
		if (name.compare( stringArr[j] ) == 0) {
			std::cout << "Inter creates " << stringArr[j] << " form.\n";
			return (this->*function[j])( target );		
		}
	}

	throw Intern::FormNotFoundExcepcion();
}