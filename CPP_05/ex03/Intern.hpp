#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		/* Make forms */ 
		AForm* makeSCF( std::string& target);
		AForm* makeRRF( std::string& target);
		AForm* makePPF( std::string& target);

		/* Exceptions */
		class NoTargetSpecifiedExcepcion : public std::exception {
			const char* what() const throw() {
				return "the target of the form is empty";
			}
		};
		class FormNotFoundExcepcion : public std::exception {
			const char* what() const throw() {
				return "Intern cannot find the proper form";
			}
		};

	public:
		/* OCCF */
		Intern();
		Intern( const Intern& other );
		Intern& operator=( const Intern& other );
		~Intern();

		/* Public Methods */
		AForm* makeForm( std::string name, std::string target );
};