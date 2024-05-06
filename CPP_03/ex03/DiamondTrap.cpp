#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap( "Default_clap_name" ) {
	this->name = "Default";
	this->energyPoints = 50;

	std::cout << "Default DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap( std::string _name ): ClapTrap( _name + "_clap_name" ) {
	this->name = _name;
	this->energyPoints = 50;

	std::cout << name << " DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << other.name << " DiamondTrap created with copy constructor" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other ) {

	if (this != &other) {
		this->name = other.getName();
		this->ClapTrap::name = other.getName() + "_clap_name";
		this->hitPoints = other.getHP();
		this->energyPoints = other.getEP();
		this->attackDamage = other.getAD();
		this->maxHitPoints = other.getMaxHP();
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->name << " DiamondTrap destroyed" << std::endl;
}

/* Public Methods */
void	DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap name: " << name << ". ClapTrap name: " << ClapTrap::name << "." << std::endl;
}

std::string DiamondTrap::getName() const { return name; }

