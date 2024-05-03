#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void ) {
	{
		/* Constructor & destructor testing */
		DiamondTrap a;
		DiamondTrap b( "Pepe" );
		DiamondTrap c( a );
		DiamondTrap d;
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
		/* Repair and takeDamage */
		DiamondTrap a( "Pepe" );

		// shared methods
		a.takeDamage(5);
		a.beRepaired(5);

		for(int i = 0; i < 15; i++) {
			std::cout << i + 1 << ". ";
			a.takeDamage(10);
		}
		a.beRepaired(5);

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* whoAmI, highFiveGuys & attack methods */
		DiamondTrap a;

		a.whoAmI();

		a.highFivesGuys();
		a.attack("Pedro");

		a.takeDamage(100);

		a.highFivesGuys();
		a.attack("Pedro");

	}

	return 0;
}