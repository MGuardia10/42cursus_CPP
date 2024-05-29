#pragma once

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include "AForm.hpp"

#define SIGN_ROBOTOMY 72
#define EXEC_ROBOTOMY 45

class RobotomyRequestForm : public AForm {
	
	public:
		/* OCCF */
		RobotomyRequestForm();
		RobotomyRequestForm( const std::string _target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
		~RobotomyRequestForm();

		/* Public Methods */
		virtual void execute(Bureaucrat const & executor) const; // override
};