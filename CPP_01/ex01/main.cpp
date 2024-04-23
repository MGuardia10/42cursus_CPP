#include "Zombie.h"

int main( void ) {

	int N = 10;
	Zombie *zombies = zombieHorde(N, "zombie_");

	for (int i = 0; i < N; i++)
		zombies[i].announce();

	delete[] zombies;

	return 0;
}
