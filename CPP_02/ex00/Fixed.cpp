#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=( const Fixed& obj ) {
	
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &obj)
        this->rawBits = obj.getRawBits();
    
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits( int const nbr ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = nbr;
}
