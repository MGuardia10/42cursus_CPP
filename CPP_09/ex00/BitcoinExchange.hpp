#pragma once

#include <iostream>
#include <map>

class BitcoinExchange {
	private:
		static std::map<std::string, float> dataBase;

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

	public:
		BitcoinExchange& operator=( const BitcoinExchange& other );
		static void setDataBase( const std::string pathDB );

};
