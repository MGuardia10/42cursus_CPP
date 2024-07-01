#include "BitcoinExchange.hpp"

/* OCCF */
BitcoinExchange::BitcoinExchange() : dataBase() {}
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
static void trim( std::string& str ) {
	str.erase(0, str.find_first_not_of( WHITESPACES ));
	str.erase(str.find_last_not_of( WHITESPACES ) + 1);
}

static bool isValidDate( std::string date ) {

	size_t pos1 = date.find('-');
	size_t pos2 = date.rfind('-');

	if (pos1 == pos2) {
		return false;
	}

	std::string year = date.substr( 0, pos1 );
	std::string month = date.substr( pos1 + 1, pos2 - (pos1 + 1));
	std::string day = date.substr( pos2 + 1 );

	if ( year.size() != 4 || month.size() != 2 || day.size() != 2) {
		return false;
	}

	char *stringEnd = NULL;
	strtol( year.c_str(), &stringEnd, 10);
	if ( *stringEnd ) {
		return false;
	}

	long monthNbr = strtol( month.c_str(), &stringEnd, 10 );
	if ( *stringEnd || monthNbr < 1 || monthNbr > 12 ) {
		return false;
	}

	long dayNbr = strtol( day.c_str(), &stringEnd, 10 );
	if ( *stringEnd || dayNbr < 1 || dayNbr > 31 ) {
		return false;
	}

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
		
		/* Date parsing */
		std::string date = content.substr( 0, pos );
		trim( date );

		/* Price parsing */
		std::string priceStr = content.substr( pos + 1, content.npos );
		trim( priceStr );
		char *priceEnd = NULL;
		double price = strtod( priceStr.c_str() , &priceEnd );

		if ( !isValidDate( date ) || *priceEnd ) {
			throw BitcoinExchange::parsingDataBaseException();
		}
		
		/* Insert pair on database */
		dataBase.insert( std::make_pair( date, price ) );
	}

	DBfile.close();
}

void BitcoinExchange::calculate( const std::string pathFile ) {
	
	/* open file */
	std::ifstream	file( pathFile.c_str() );

	if ( file.fail() ) {
		throw BitcoinExchange::openingFileException();
	}

	std::string content;
	std::getline( file, content ); // take header
	while (std::getline( file, content )) {
		/* find '|' */
		size_t pos = content.find('|');
		if ( pos == std::string::npos ) {
			std::cout << "Error: bad input => " << content << '\n';
			continue;
		}

		/* date parsing */
		std::string date = content.substr( 0, pos );
		trim( date );
		if ( !isValidDate( date ) ) {
			std::cout << "Error: bad input => " << date << '\n';
			continue;
		}

		/* btcAmount parsing */
		std::string amountStr = content.substr( pos + 1, content.npos );
		trim( amountStr );
		char *amountEnd = NULL;
		double btcAmount = strtod( amountStr.c_str() , &amountEnd );

		if ( *amountEnd ) {
			std::cout << "Error: bad input => " << amountStr << '\n';
			continue;
		}
		if ( btcAmount > 1000 ) {
			std::cout << "Error: too large a number.\n";
			continue;
		}

		if ( btcAmount < 0 ) {
			std::cout << "Error: not a positive number.\n";
			continue;
		}

		/* Find date in database */
		std::map<std::string, double>::iterator it = dataBase.upper_bound( date ); // returns first ocurrence higher than the input (date)
		if ( it == dataBase.begin() ) {
			std::cout << "Error: cannot find data to date => " << date << '\n';
			continue;
		}

		std::pair<std::string, double> element = *(--it);

		/* Print total value */
		double total = btcAmount * element.second;
		std::cout << date << " => " << btcAmount << " = " << total << '\n';

	}
}
