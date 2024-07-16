#include "ShrubberyCreationForm.hpp"

/* OCCF*/
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation form", "Default_target", SIGN_SHRUBBERY, EXEC_SHRUBBERY) {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string _target ): AForm("shrubbery creation form", _target, SIGN_SHRUBBERY, EXEC_SHRUBBERY) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ): AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecGrade()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	if (this != &other)
		this->setIsSigned(other.getIsSigned());
		
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Exceptions */
const char* ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return "error opening the file";
}

/* Public Methods */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException(); // error de no firmado
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException(); // error de no exec grade
	
	std::ofstream file((this->getTarget() + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);


	if (!file.is_open()) {
		throw ShrubberyCreationForm::FileNotOpenException();
	}

	file << "                $\n";
	file << "               $$$\n";
	file << "              $$$$$\n";
	file << "             $$$$$$$\n";
	file << "            $$$$$$$$$\n";
	file << "           $$$$$$$$$$$\n";
	file << "          $$$$$$$$$$$$$\n";
	file << "         $$$$$$$$$$$$$$$\n";
	file << "        $$$$$$$$$$$$$$$$$\n";
	file << "       $$$$$$$$$$$$$$$$$$$\n";
	file << "      $$$$$$$$$$$$$$$$$$$$$\n";
	file << "     $$$$$$$$$$$$$$$$$$$$$$$\n";
	file << "    $$$$$$$$$$$$$$$$$$$$$$$$$\n";
	file << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	file << "  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	file << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	file << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	file << "             #######\n";
	file << "             #######\n";
	file << "             #######\n";
	file << "             #######\n";
	file << "             #######\n";

	file.close();

}