#include "Animal.hpp"

/* Orthodox canonical class form */
Animal::Animal(): type("No type specified") {
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal( const Animal& other ) {
	std::cout << "Default Animal copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=( const Animal& other ) {
	std::cout << "Default Animal copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Default Animal destructor called" << std::endl;
}

/* Public Methods */
std::string	Animal::getType() const { return this->type; }
