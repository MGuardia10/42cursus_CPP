#pragma once

#include <iostream>

class Data {
	private:
		std::string str;

	public:
		Data();
		Data( const Data& other );
		Data& operator=( const Data& other );
		~Data();

		std::string	getStr() const;
		void 		setStr( std::string _str );
};