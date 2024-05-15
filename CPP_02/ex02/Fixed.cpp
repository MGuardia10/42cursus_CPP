#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

/* Orthodox Canonical Class Form */
Fixed::Fixed(): rawBits(0) {}

Fixed::Fixed( const int nbr ) {
	this->rawBits = (nbr << fractionalBits);
}

Fixed::Fixed( const float nbr ) {
	this->rawBits = roundf( nbr * (1 << fractionalBits) );
}

Fixed::Fixed( const Fixed &copy ) {
	*this = copy;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	if (this != &other)
        rawBits = other.getRawBits();
    
	return *this;
}

Fixed::~Fixed() {}

/* Getters & Setters */
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

