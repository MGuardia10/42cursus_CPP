#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {
	{
		/* Constructor & destructor testing */
		ScavTrap a;
		ScavTrap b( "Pepe" );
		ScavTrap c( a );
		ScavTrap d;
		d = b;

		std::cout << a.getName() << ": HP: " << a.getHP() << ", AD: " << a.getAD() << ", EP: " << a.getEP() << std::endl;
		std::cout << b.getName() << ": HP: " << b.getHP() << ", AD: " << b.getAD() << ", EP: " << b.getEP() << std::endl;
		std::cout << c.getName() << ": HP: " << c.getHP() << ", AD: " << c.getAD() << ", EP: " << c.getEP() << std::endl;
		std::cout << d.getName() << ": HP: " << d.getHP() << ", AD: " << d.getAD() << ", EP: " << d.getEP() << std::endl;

		a.attack("Juan");

		std::cout << &a << std::endl;
		std::cout << &b << std::endl;
		std::cout << &c << std::endl;
		std::cout << &d << std::endl;

		ClapTrap aa;

		std::cout << aa.getName() << ": HP: " << aa.getHP() << ", AD: " << aa.getAD() << ", EP: " << aa.getEP() << std::endl;
		aa.attack("Juan");

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Attack, Repair and take damage */
		ScavTrap a( "Pepe" );
		ClapTrap b( "Pepe" );

		// different messages
		a.attack("Juan");
		b.attack("Juan");

		// shared methods
		a.takeDamage(5);
		b.takeDamage(5);

		a.beRepaired(5);
		b.beRepaired(5);

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* guardGate method */
		ScavTrap a( "Pepe" );

		a.guardGate();

		a.takeDamage(100);

		a.guardGate();

	}

	return 0;
}