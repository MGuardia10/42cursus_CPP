#include "ScavTrap.hpp"

/* Orthodox canonical Class */
ScavTrap::ScavTrap() {

	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->maxHitPoints = 100;

	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap( std::string _name ): ClapTrap(_name) {

	this->name = _name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->maxHitPoints = 100;
	
	std::cout << this->name << " ScavTrap created" << std::endl;

}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap() {
	std::cout << other.name << " ScavTrap created with copy constructor" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other ) {

	if (this != &other) {
		this->name = other.getName();
		this->hitPoints = other.getHP();
		this->energyPoints = other.getEP();
		this->attackDamage = other.getAD();
		this->maxHitPoints = other.getMaxHP();
	}

	std::cout << this->name << " ScavTrap created with copy assignment operator" << std::endl;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << this->name << " ScavTrap destroyed" << std::endl;
}

/* Public Methods */
void	ScavTrap::attack( const std::string& target ) {	
	if (target.empty()) {
		std::cout << this->name << " ScavTrap failed to attack, no target specified\n";
		return ;
	}
	if (this->getHP() == 0) {
		std::cout << this->name << " ScavTrap cannot attack because it has no HP\n";
		return ;
	}
	if (this->getEP() == 0) {
		std::cout << this->name << " ScavTrap cannot attack because it has no EP\n";
		return ;
	}

	this->energyPoints--;

	std::cout << this->name << " ScavTrap";
	std::cout << " attacks " << target;
	std::cout << " causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() {
	if (this->getHP() != 0)
		std::cout << this->name << " ScavTrap is now in Gate Keeper mode" << std::endl;
	else
		std::cout << this->name << " ScavTrap cannot be in Gate Keeper mode. It's dead" << std::endl;
}

