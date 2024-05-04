#include "WrongAnimal.hpp"

/* Orthodox canonical class form */
WrongAnimal::WrongAnimal(): type("No type specified") {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {
	std::cout << "Default WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
	std::cout << "Default WrongAnimal copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Default WrongAnimal destructor called" << std::endl;
}

/* Public Methods */
std::string	WrongAnimal::getType() const { return this->type; }
void	WrongAnimal::makeSound() const { std::cout << "No sound sorry" << std::endl; }
