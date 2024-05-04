#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Empty";
}

Brain::Brain( const Brain& other ) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=( const Brain& other ) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}

	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/* Public Methods */
void	Brain::getIdea( int index ) {
	if (index < 0 || index > 99)
		std::cout << "Could not show the idea. Index must be between 0 and 99." << std::endl;
	else
		std::cout << index + 1 << ". Idea: [ " << this->ideas[index] << " ]" << std::endl;
}

void	Brain::addIdea( std::string idea, int index ) {
	if (index < 0 || index > 99) {
		std::cout << "Could not add idea. Index must be between 0 and 99." << std::endl;
		return ;
	}

	if (idea.empty())
		this->ideas[index] = "Empty";
	else
		this->ideas[index] = idea;

	std::cout << "Idea succesfully added!" << std::endl;
}

void	Brain::printIdeas() {
	for (int i = 0; i < 100; i++) {
		std::cout << i + 1 << ". Idea: [ " << this->ideas[i] << " ]" << std::endl;
	}
}
