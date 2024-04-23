#include "Zombie.h"

Zombie::Zombie( void ) {}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie( void ) {
	std::cout << RED << this->name << " died." << RESET << std::endl;
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

void	Zombie::announce( void ) {
	std::cout << GREEN << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

