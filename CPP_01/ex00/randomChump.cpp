#include "Zombie.h"

void	randomChump( std::string name ) {
	
	Zombie randomZombie(name);
	randomZombie.announce();
}
