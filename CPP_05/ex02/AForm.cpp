#include "AForm.hpp"

/* Orthodox Canonical Class Form */
AForm::AForm(): name("Default"), target("Default_form"), isSigned(false), signGrade(1), execGrade(1) {}

AForm::AForm( std::string _name, std::string _target, int _signGrade, int _execGrade ): name(_name), target(_target), signGrade(_signGrade), execGrade(_execGrade) {
	if (_signGrade < 1)
		throw AForm::GradeTooHighException();
	if (_execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150)
		throw AForm::GradeTooLowException();
	if (_execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm ( const AForm& other ): name(other.name), target(other.target), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm& AForm::operator=( const AForm& other ) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

/* Exceptions */
const char* AForm::AlreadySingedException::what() const throw() {
	return "form is already signed";
}

/* Public Methods */
std::string AForm::getName() const { return this->name; }
std::string AForm::getTarget() const { return this->target; }
const bool& AForm::getIsSigned() const { return this->isSigned; }
const unsigned int& AForm::getSignGrade() const { return this->signGrade; }
const unsigned int& AForm::getExecGrade() const { return this->execGrade; }

void AForm::setIsSigned( bool sing ) { this->isSigned = sing; }

void AForm::beSigned( const Bureaucrat& bureaucrat ) {
	if (this->isSigned == true)
		throw AForm::AlreadySingedException();
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

/* << operator overload */
std::ostream& operator<<(std::ostream& op, const AForm& form ) {
	
	op << "Form name: " << form.getName() << '\n';
	op << "\t - Form target: " << form.getTarget() << '\n';
	op << "\t - Grade to sign form: " << form.getSignGrade() << '\n';
	op << "\t - Grade to execute form: " << form.getExecGrade() << '\n';
	op << "\t - Is signed: " << (form.getIsSigned() ? "true" : "false") << '\n';

	return op;
}
