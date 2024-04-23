#include "Zombie.h"

int main( void ) {

	Zombie zombie1("Pepe");
	Zombie zombie2 = Zombie("Eustaquio");
	Zombie *zombie3 = newZombie("Manuel");
	
	randomChump("Josito");

	zombie1.announce();
	zombie2.announce();
	zombie3->announce();

	delete zombie3;

	return 0;
}