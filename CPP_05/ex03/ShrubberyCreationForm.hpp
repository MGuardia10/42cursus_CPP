#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

#define SIGN_SHRUBBERY 145
#define EXEC_SHRUBBERY 137

class ShrubberyCreationForm : public AForm {
	private:
		/* Exceptions */
		class FileNotOpenException : public std::exception {
			const char* what() const throw();
		};
	public:
		/* OCCF */
		ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string _target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm();

		/* Public Methods */
		virtual void execute(Bureaucrat const & executor) const; // override
};