#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

#define WHITESPACES 	" \t\n\v\f\r"

class BitcoinExchange {
	private:
		std::map<std::string, double> dataBase;

		/* Exceptions */
		class openingDataBaseException : public std::exception {
			const char* what() const throw();
		};

		class parsingDataBaseException : public std::exception {
			const char* what() const throw();
		};


		class openingFileException : public std::exception {
			const char* what() const throw();
		};

	public:
		/* OCCF */
		BitcoinExchange();
		BitcoinExchange( const char *pathDB );
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );
		~BitcoinExchange();

		/* Public Methods */
		void setDataBase( const char *pathDB );
		void calculate( const std::string pathFile );

};
