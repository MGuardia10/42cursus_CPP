#include "PresidentialPardonForm.hpp"

/* OCCF*/
PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential pardon form", "Default_target", SIGN_PRESIDENTIAL, EXEC_PRESIDENTIAL) {}

PresidentialPardonForm::PresidentialPardonForm( const std::string _target ): AForm("presidential pardon form", _target, SIGN_PRESIDENTIAL, EXEC_PRESIDENTIAL) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ): AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecGrade()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other)
		this->setIsSigned(other.getIsSigned());
	
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* Public Methods */
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException(); // error de no firmado
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException(); // error de no exec grade

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}