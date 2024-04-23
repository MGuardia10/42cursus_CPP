#pragma once

#include "Zombie.hpp"

/* COLORS */
#define RESET   "\033[0m"
#define RED 	"\e[1;91m"
#define GREEN 	"\e[1;92m"

/* PROTOTYPES */
Zombie* zombieHorde(int N, std::string name);