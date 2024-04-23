#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack( void ) {
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->weapon = &weapon;
}
