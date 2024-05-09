#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int nbr ) {
	std::cout << "INT constructor called" << std::endl;
	this->_rawBits = (nbr << _fractionalBits);
}

Fixed::Fixed( const float nbr ) {
	std::cout << "FLOAT constructor called" << std::endl;
	this->_rawBits = roundf( nbr * (1 << _fractionalBits) );
}

Fixed::Fixed( const Fixed &copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=( const Fixed& copy ) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) // Evitar auto-asignación
        _rawBits = copy.getRawBits();
    
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

int	Fixed::toInt( void ) const {
	return _rawBits >> _fractionalBits;
}

float	Fixed::toFloat( void ) const {
	return ((float)_rawBits / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& op, Fixed const& nbr) {
	op << nbr.toFloat();
	return op;
}

