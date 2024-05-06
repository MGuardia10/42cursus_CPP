#include "WrongCat.hpp"

/* Orthodox canonical class form */
WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal() {
	std::cout << "Default WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
	std::cout << "Default WrongCat copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Default WrongCat destructor called" << std::endl;
}

/* Public Methods */
void	WrongCat::makeSound() const { std::cout << "WrongCat sound" << std::endl; }
