#include "Zombie.h"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie( void ) {
	std::cout << RED << this->name << " died." << RESET << std::endl;
}

void 		Zombie::announce( void ) {
	std::cout << GREEN << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

