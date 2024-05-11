#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

/* Orthodox Canonical Class Form */
Fixed::Fixed(): rawBits(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int nbr ) {
	// std::cout << "INT constructor called" << std::endl;
	this->rawBits = (nbr << fractionalBits);
}

Fixed::Fixed( const float nbr ) {
	// std::cout << "FLOAT constructor called" << std::endl;
	this->rawBits = roundf( nbr * (1 << fractionalBits) );
}

Fixed::Fixed( const Fixed &copy ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
        rawBits = other.getRawBits();
    
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

/* Getters & Setters */
int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}

/* Public Methods */
int	Fixed::toInt( void ) const {
	return rawBits >> fractionalBits;
}

float	Fixed::toFloat( void ) const {
	return ((float)rawBits / (1 << fractionalBits));
}

Fixed& Fixed::min( Fixed& a, Fixed& b ) {
	if (b.toFloat() < a.toFloat())
		return b;
	return a;
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
	if (b.toFloat() < a.toFloat())
		return b;
	return a;
}

Fixed& Fixed::max( Fixed& a, Fixed& b ) {
	if (b.toFloat() > a.toFloat())
		return b;
	return a;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
	if (b.toFloat() > a.toFloat())
		return b;
	return a;
}

/* Overload operators */
// Comparison operators
bool Fixed::operator!=( const Fixed& other ) {
	return this->toFloat() != other.toFloat();
}

bool Fixed::operator==( const Fixed& other ) {
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator>=( const Fixed& other ) {
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=( const Fixed& other ) {
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>( const Fixed& other ) {
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator<( const Fixed& other ) {
	return this->toFloat() < other.toFloat();
}

// Arithmetic operators
Fixed Fixed::operator+( const Fixed& other ) {
	return Fixed( this->toFloat() + other.toFloat() );
}

Fixed Fixed::operator-( const Fixed& other ) {
	return Fixed( this->toFloat() - other.toFloat() );
}

Fixed Fixed::operator/( const Fixed& other ) {
	return Fixed( this->toFloat() / other.toFloat() );
}

Fixed Fixed::operator*( const Fixed& other ) {
	return Fixed( this->toFloat() * other.toFloat() );
}

// Increment / Decrement operators
Fixed Fixed::operator++( int n ) { //i++
	Fixed tmp = *this;

	if (n != 0)
		rawBits += n;
	else
		rawBits++;

	return tmp;
}

Fixed& Fixed::operator++( void ) { //++i
	this->rawBits++;
	return *this;
}

Fixed Fixed::operator--( int n ) { //i--
	Fixed tmp = *this;

	if (n != 0)
		this->rawBits -= n;
	else
		this->rawBits--;

	return tmp;
}

Fixed& Fixed::operator--( void ) { //--i
	this->rawBits--;
	return *this;
}

/* operator << overload */
std::ostream& operator<<(std::ostream& op, Fixed const& nbr) {
	op << nbr.toFloat();
	return op;
}

