#include "Cat.hpp"

/* Orthodox canonical class form */
Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(), brain( new Brain ) {
	std::cout << "Default Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=( const Cat& other ) {
	std::cout << "Default Cat copy assignment operator called" << std::endl;
	
	if (this != &other) {
		this->type = other.type;
		*(this->brain) = *(other.brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Default Cat destructor called" << std::endl;
	delete brain;
}

/* Public Methods */
void	Cat::makeSound() const { std::cout << "Meowwwww Meowwwww" << std::endl; }
void	Cat::addIdea( std::string idea, int index ) { brain->addIdea( idea, index ); }
void	Cat::getIdea( int index ) const { brain->getIdea( index ); }
