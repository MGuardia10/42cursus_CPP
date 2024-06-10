#include "Data.hpp"

/* OCCF */
Data::Data(): str("Default") {}
Data::Data( const Data& other ) {
	*this = other;
}

Data& Data::operator= (const Data& other ) {
	if (this != &other)
		str = other.str;
	return *this;
}

Data::~Data() {}

/* Getter & Setter */
std::string	Data::getStr() const { return str; }
void 	Data::setStr( std::string _str ) { str = _str; }
