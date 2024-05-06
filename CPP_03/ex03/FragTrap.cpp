#include "FragTrap.hpp"

FragTrap::FragTrap() {

	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::FragTrap( std::string _name ): ClapTrap(_name) {

	this->name = _name;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	
	std::cout << this->name << " FragTrap created" << std::endl;

}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap() {
	std::cout << other.name << " FragTrap created with copy constructor" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=( const FragTrap& other ) {

	if (this != &other) {
		this->name = other.getName();
		this->hitPoints = other.getHP();
		this->energyPoints = other.getEP();
		this->attackDamage = other.getAD();
		this->maxHitPoints = other.getMaxHP();
	}

	std::cout << this->name << " FragTrap created with copy assignment operator" << std::endl;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << this->name << " FragTrap destroyed" << std::endl;
}

/* Public Methods */
void	FragTrap::highFivesGuys() {
	if (this->getHP() != 0)
		std::cout << this->name << " FragTrap: Hey there! Can I get a high five?" << std::endl;
	else
		std::cout << this->name << " FragTrap cannot get a high five because is dead :(" << std::endl;
}