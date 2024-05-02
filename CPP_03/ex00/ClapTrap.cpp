#include "ClapTrap.hpp"

/* Orthodox canonical Class */
ClapTrap::ClapTrap(): name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string _name): name(_name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << this->name << " ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) {
	std::cout << other.name << " ClapTrap created with copy constructor" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
	
	if (this != &other) {
		this->name = other.getName();
		this->hitPoints = other.getHP();
		this->energyPoints = other.getEP();
		this->attackDamage = other.getAD();
	}

	std::cout << this->name << " ClapTrap created with copy assignment operator" << std::endl;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << this->name << " ClapTrap destroyed" << std::endl;
}

/* Methods */
void	ClapTrap::attack(const std::string& target) {
	
	if (target.empty()) {
		std::cout << this->name << " failed to attack, no target specified\n";
		return ;
	}
	if (this->getHP() == 0) {
		std::cout << this->name << " cannot attack because it has no HP\n";
		return ;
	}
	if (this->getEP() == 0) {
		std::cout << this->name << " cannot attack because it has no EP\n";
		return ;
	}

	this->energyPoints--;

	std::cout << "ClapTrap " << this->name;
	std::cout << " attacks " << target;
	std::cout << " causing " << this->attackDamage << " points of damage!" << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (this->getHP() == 0) {
		std::cout << this->name << " it's already dead!\n";
		return ;
	}

	(amount > this->getHP()) ? this->setHP(0) : this->setHP(this->hitPoints - amount);
	
	std::cout << "ClapTrap " << this->name;
	std::cout << " has taken " << amount << " points of damage.";

	if (this->getHP() == 0)
		std::cout << " ClapTrap " << this->name << " it's now dead :(" << std::endl;
	else
		std::cout << " ClapTrap " << this->name << " current HP is: " << this->getHP() << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->getHP() == 10) {
		std::cout << this->name << " cannot be repaired because it has full HP\n";
		return ;
	}
	if (this->getHP() == 0) {
		std::cout << this->name << " cannot be repaired because it has no HP\n";
		return ;
	}
	if (this->getEP() == 0) {
		std::cout << this->name << " cannot be repaired because it has no EP\n";
		return ;
	}

	this->energyPoints--;
	(this->hitPoints + amount > 10) ? this->setHP(10) : this->setHP(hitPoints + amount);
	
	std::cout << "ClapTrap " << this->name << " repaired himself successfully!";
	std::cout << " Current HP: " << this->getHP() << std::endl;
}

/* Getters */
std::string		ClapTrap::getName( void ) const { return this->name; }
unsigned int	ClapTrap::getHP( void ) const { return this->hitPoints; }
unsigned int	ClapTrap::getEP( void ) const { return  this-> energyPoints; }
unsigned int	ClapTrap::getAD( void ) const { return  this->attackDamage; }

/* Setters */
void	ClapTrap::setName( std::string name ) { this->name = name; }
void	ClapTrap::setHP( unsigned int hitPoints ) { this->hitPoints = hitPoints; }
void	ClapTrap::setEP( unsigned int energyPoints ) { this->energyPoints = energyPoints; }
void	ClapTrap::setAD( unsigned int attackDamage ) { this->attackDamage = attackDamage; }
