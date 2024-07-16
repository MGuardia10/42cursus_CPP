#pragma once

#include "Form.hpp"
#include <iostream>

class Form;

class Bureaucrat {
	private: 
		const std::string	name;
		unsigned int		grade;
		
		/* Exceptions */
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

	public:
		/* Orthodox Canonical Class Form */
		Bureaucrat();
		Bureaucrat( std::string _name, int _grade = 150 );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat();


		/* Public methods */
		std::string const getName( void ) const;
		unsigned int getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );

		void	signForm( Form& form ) const;
};

std::ostream& operator<<( std::ostream& op, const Bureaucrat& bureaucrat );