#pragma once

#include <iostream>

/* COLORS */
#define RESET   "\033[0m"
#define RED 	"\e[1;91m"
#define BLUE 	"\e[1;94m"
#define GREEN 	"\e[1;92m"
#define MAG		"\e[1;95m"

class	Harl {

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
	public:
		Harl();
		~Harl();
		void complain( std::string level );
};
