#include "Form.hpp"

/* Orthodox Canonical Class Form */
Form::Form(): name("Default"), isSigned(false), signGrade(1), execGrade(1) {}

Form::Form( std::string _name, int _signGrade, int _execGrade ): name(_name), signGrade(_signGrade), execGrade(_execGrade) {
	if (_signGrade < 1)
		throw Form::GradeTooHighException();
	if (_execGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150)
		throw Form::GradeTooLowException();
	if (_execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form ( const Form& other ): name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

Form& Form::operator=( const Form& other ) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

/* Public Methods */
std::string Form::getName() const { return this->name; }
const bool& Form::getIsSigned() const { return this->isSigned; }
const unsigned int& Form::getSignGrade() const { return this->signGrade; }
const unsigned int& Form::getExecGrade() const { return this->execGrade; }

void Form::beSigned( const Bureaucrat& bureaucrat ) {
	if (this->isSigned == true)
		throw Form::AlreadySingedException();
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

/* << operator overload */
std::ostream& operator<<(std::ostream& op, const Form& form ) {
	
	op << "Form name: " << form.getName() << '\n';
	op << "\t - Grade to sign form: " << form.getSignGrade() << '\n';
	op << "\t - Grade to execute form: " << form.getExecGrade() << '\n';
	op << "\t - Is signed: " << (form.getIsSigned() ? "true" : "false") << '\n';

	return op;
}
