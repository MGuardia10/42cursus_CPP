#include "ClapTrap.hpp"

int	main( void ) {
	{
		/* Orthodox canonical form test */
		ClapTrap a;
		ClapTrap b( a );
		ClapTrap c("Juan");
		ClapTrap d;
		d = c;

		std::cout << a.getName() << std::endl;
		std::cout << b.getName() << std::endl;
		std::cout << c.getName() << std::endl;
		std::cout << d.getName() << std::endl;

		std::cout << &a << std::endl;
		std::cout << &b << std::endl;
		std::cout << &c << std::endl;
		std::cout << &d << std::endl;
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Attack test */
		ClapTrap a( "Dani" );

		std::cout << "Attack damage: " << a.getAD() << std::endl;
		std::cout << "Energy points: " << a.getEP() << std::endl;
		std::cout << "Hit Points: " << a.getHP() << std::endl;

		a.attack("");

		for (int i = 0; i < 15; i++) {
			std::cout << i + 1 << ". ";
			a.attack("Alvaro");
		}

		std::cout << "Attack damage: " << a.getAD() << std::endl;
		std::cout << "Energy points: " << a.getEP() << std::endl;
		std::cout << "Hit Points: " << a.getHP() << std::endl;

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* TakeDamage and beRepaired test */
		ClapTrap a( "Manuel" );

		a.beRepaired(3); // Cannot repair bc full HP
		
		a.takeDamage(5);
		for (int i = 0; i < 7; i++)
			a.beRepaired(1); // repair until 10 HP and then throw cannot repair error

		a.takeDamage(10000); // Kill ClapTrap

		a.takeDamage(1); // cannot receive more damage bc is dead
		a.beRepaired(100); // cannot repair bc is dead
	}
	
	return 0;
}