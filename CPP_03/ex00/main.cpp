#include "ClapTrap.hpp"

int	main( void ) {
	{
		/* Orthodox canonical form test */
		ClapTrap a( "Pedro" );
		ClapTrap b( a );
		ClapTrap c = a;
		ClapTrap d;

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

		/* Cannot repair himself because its full HP */
		a.beRepaired(3);

		/* Take damage until 5 HP */
		a.takeDamage(5);

		/* now repair one by one HP */
		for (int i = 0; i < 7; i++)
			a.beRepaired(1);

		/* Kill Manuel */
		a.takeDamage(10000);

		/* Try to receive more damage when its dead */
		a.takeDamage(1);

		/* Try to repair it dead */
		a.beRepaired(100);
	}
	
	return 0;
}