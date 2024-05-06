#include "Dog.hpp"

/* Orthodox canonical class form */
Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& other ): Animal(), brain( new Brain() ){
	std::cout << "Default Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=( const Dog& other ) {
	std::cout << "Default Dog copy assignment operator called" << std::endl;
	
	if (this != &other) {
		this->type = other.type;
		*this->brain = *(other.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Default Dog destructor called" << std::endl;
	delete brain;
}

/* Public Methods */
void	Dog::makeSound() const { std::cout << "Wooooff Wooooff" << std::endl; }
void	Dog::addIdea( std::string idea, int index ) { brain->addIdea( idea, index ); }
void	Dog::getIdea( int index ) const { brain->getIdea( index ); }