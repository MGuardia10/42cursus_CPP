#include "BitcoinExchange.hpp"

/* OCCF */
BitcoinExchange::BitcoinExchange() : dataBase() {}  //mirar
BitcoinExchange::BitcoinExchange( const char *pathDB ) : dataBase() { this->setDataBase( pathDB ); }
BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) { *this = other; }
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) {
	if (this != &other) {
		dataBase = other.dataBase;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

/* Exposed methods */
static bool isValidDate( std::string date ) {
	
	return true;
}

void BitcoinExchange::setDataBase( const char *pathDB ) {

	std::ifstream	DBfile( pathDB );

	if ( DBfile.fail() ) {
		throw BitcoinExchange::openingDataBaseException();
	}

	std::string content;

	std::getline( DBfile, content ); // take header
	while (std::getline( DBfile, content )) {		
		size_t pos = content.find(',');
		if ( pos == std::string::npos ) {
			throw BitcoinExchange::parsingDataBaseException();
		}
		
		std::string date = content.substr( 0, pos );
		char *priceEnd = NULL;
		float price = strtod( content.substr( pos + 1, content.npos ).c_str() , &priceEnd );
		if ( !isValidDate( date ) || *priceEnd ) {
			throw BitcoinExchange::parsingDataBaseException();
		}
		
		dataBase.insert( std::make_pair( date, price ) );
	}

	DBfile.close();
}

void BitcoinExchange::calculate( const std::string pathFile ) {
	(void)pathFile;
}

/*
	Posibles errores
		- que no se encuentre delimitador OK
		- Al convertir a double que haya cosas x detras OK
		- Espacios al principio y final de fecha - valor
		- Fecha formato invalido
*/




