#include "Bureaucrat.hpp"

/* Orthodox Canonical Class Form */
Bureaucrat::Bureaucrat(): name("Default"), grade(150) {}

Bureaucrat::Bureaucrat( std::string _name, int _grade ): name(_name) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();

	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();

	this->grade = _grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
		this->grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

/* Public Methods */
std::string const Bureaucrat::getName() const { return this->name; }
unsigned int Bureaucrat::getGrade() const { return this->grade; }

void	Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm( Form& form ) const {
	try {
		form.beSigned( *this );
		std::cout << this->name << " signed " << form.getName() << '\n'; 
	} catch (std::exception &e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << '\n'; 
	}
}


/* << operator overload */
std::ostream& operator<<( std::ostream& op, const Bureaucrat& bureaucrat ) {
	op << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return op;
}
