#include "Dog.hpp"

/* Orthodox canonical class form */
Dog::Dog() {
	this->type = "Dog";
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal() {
	std::cout << "Default Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=( const Dog& other ) {
	std::cout << "Default Dog copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Default Dog destructor called" << std::endl;
}

/* Public Methods */
void	Dog::makeSound() const { std::cout << "Wooooff Wooooff" << std::endl; }