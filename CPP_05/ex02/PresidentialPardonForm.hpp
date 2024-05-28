#pragma once

#include <iostream>
#include "AForm.hpp"

#define SIGN_PRESIDENTIAL 25
#define EXEC_PRESIDENTIAL 5

class PresidentialPardonForm : public AForm {
	
	public:
		/* OCCF */
		PresidentialPardonForm();
		PresidentialPardonForm( const std::string _target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
		~PresidentialPardonForm();

		/* Public Methods */
		virtual void execute(Bureaucrat const & executor) const; // override
};