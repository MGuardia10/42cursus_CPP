#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> dataBase;

		/* exceptions */
		class openingDataBaseException : public std::exception {
			const char* what() const throw() {
				return "Error: Cannot open database file";
			}
		};

		class parsingDataBaseException : public std::exception {
			const char* what() const throw() {
				return "Error: database cannot be parsed";
			}
		};


		class openingFileException : public std::exception {
			const char* what() const throw() {
				return "Error: Cannot open the file specified";
			}
		};

	public:
		/* OCCF */
		BitcoinExchange();
		BitcoinExchange( const char *pathDB );
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );
		~BitcoinExchange();

		/* Exposed Methods */
		void setDataBase( const char *pathDB );
		void calculate( const std::string pathFile );

};
