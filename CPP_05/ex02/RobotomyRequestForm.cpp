#include "RobotomyRequestForm.hpp"

/* OCCF*/
RobotomyRequestForm::RobotomyRequestForm(): AForm("robotomy request form", "Default_target", SIGN_ROBOTOMY, EXEC_ROBOTOMY) {}

RobotomyRequestForm::RobotomyRequestForm( const std::string _target ): AForm("robotomy request form", _target, SIGN_ROBOTOMY, EXEC_ROBOTOMY) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ): AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecGrade()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other)
		this->setIsSigned(other.getIsSigned());
	
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* Public Methods */
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException(); // error de no firmado
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException(); // error de no exec grade

	for (int i = 0; i < 3; i++)
		std::cout << "Brrrrr...\n";

	std::srand(static_cast<unsigned int>(time(0))); // evitar que cada ejecucion genere misma secuencia de nums random

	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been successfully robotomized!\n";
	else
		std::cout << "Robotomy on " << this->getTarget() << " failed :(\n";


}