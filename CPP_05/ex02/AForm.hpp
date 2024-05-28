#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		const std::string target;
		bool	isSigned;
		const unsigned int signGrade;
		const unsigned int execGrade;
		
		class AlreadySingedException : public std::exception {
			const char* what() const throw() {
				return "form is already signed";
			}
		};

	public:
		/* Orthodox Canonical Class Form */
		AForm();
		AForm( std::string _name, std::string _target, int _signGrade = 1, int _execGrade = 1 );
		AForm ( const AForm& other );
		AForm& operator=( const AForm& other );
		virtual ~AForm();

		/* Exceptions */
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
		class FormNotSignedException : public std::exception {
			const char* what() const throw() {
				return "form is not signed";
			}
		};

		/* Public Methods */
		std::string getName() const;
		std::string getTarget() const;
		const bool& getIsSigned() const;
		const unsigned int& getSignGrade() const;
		const unsigned int& getExecGrade() const;

		void setIsSigned( bool sign );

		void beSigned( const Bureaucrat& bureaucrat );
		virtual void execute(Bureaucrat const & executor) const = 0;
};

/* << operator overload */
std::ostream& operator<<(std::ostream& op, const AForm& form );