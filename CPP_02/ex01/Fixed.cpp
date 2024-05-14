#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

/* Orthodox Canonical Class Form */
Fixed::Fixed(): rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int nbr ) {
	std::cout << "INT constructor called" << std::endl;
	this->rawBits = (nbr << fractionalBits);
}

Fixed::Fixed( const float nbr ) {
	std::cout << "FLOAT constructor called" << std::endl;
	this->rawBits = roundf( nbr * (1 << fractionalBits) );
}

Fixed::Fixed( const Fixed &copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
        this->rawBits = other.getRawBits();
    
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* Getters & setters */
int Fixed::getRawBits( void ) const {
	return this->rawBits;
}

void Fixed::setRawBits( int const raw ) {
	this->rawBits = raw;
}

/* Public Methods */
int	Fixed::toInt( void ) const {
	return rawBits >> fractionalBits;
}

float	Fixed::toFloat( void ) const {
	return ((float)rawBits / (1 << fractionalBits));
}

/* operator << overload */
std::ostream& operator<<(std::ostream& op, Fixed const& nbr) {
	op << nbr.toFloat();
	return op;
}
