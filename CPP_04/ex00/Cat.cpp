#include "Cat.hpp"

/* Orthodox canonical class form */
Cat::Cat() {
	this->type = "Cat";
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& other ) {
	std::cout << "Default Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=( const Cat& other ) {
	std::cout << "Default Cat copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Default Cat destructor called" << std::endl;
}

/* Public Methods */
// std::string	Cat::getType() { return this->type; }
void	Cat::makeSound() const { std::cout << "Meowwwww Meowwwww" << std::endl; }
