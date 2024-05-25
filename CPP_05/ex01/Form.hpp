#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool	isSigned;
		const unsigned int signGrade;
		const unsigned int execGrade;
		
		class GradeTooHighException : public std::exception {
			const char* what() const throw() {
				return "grade too high";
			}
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw() {
				return "grade too low";
			}
		};
		class AlreadySingedException : public std::exception {
			const char* what() const throw() {
				return "form is already signed";
			}
		};

	public:
		/* Orthodox Canonical Class Form */
		Form();
		Form( std::string _name, int _signGrade = 1, int _execGrade = 1 );
		Form ( const Form& other );
		Form& operator=( const Form& other );
		~Form();

		/* Public Methods */
		std::string getName() const;
		const bool& getIsSigned() const;
		const unsigned int& getSignGrade() const;
		const unsigned int& getExecGrade() const;

		void beSigned( const Bureaucrat& bureaucrat );
};

/* << operator overload */
std::ostream& operator<<(std::ostream& op, const Form& form );