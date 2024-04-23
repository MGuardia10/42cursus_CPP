#pragma once

#include <iostream>
#include <fstream>

/* COLORS */
#define RESET   "\033[0m"
#define RED 	"\e[1;91m"
#define GREEN 	"\e[1;92m"

class	FileManager {
	
	private:
		std::string	fileName;
	
	public:
		FileManager( std::string fileName );
		~FileManager();

		std::string	readFromFile( void );
		void		writeToFile( std::string content );
		void		replaceString( std::string str1, std::string str2 );
};
