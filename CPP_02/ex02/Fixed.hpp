#pragma once

#include <iostream>

class	Fixed {

	private:
		int					_rawBits;
		static int const	_fractionalBits;

	public:

		/* Orthodox Canonical From*/
		Fixed();
		Fixed( const int nbr );
		Fixed( const float nbr );
		Fixed( const Fixed& copy );
		Fixed& operator=( const Fixed& other );
		~Fixed();

		/* Overload operators */
		// Comparison operators
		bool operator!=( const Fixed& other );
		bool operator==( const Fixed& other );
		bool operator>=( const Fixed& other );
		bool operator<=( const Fixed& other );
		bool operator>( const Fixed& other );
		bool operator<( const Fixed& other );

		// Arithmetic operators
		Fixed& operator+( const Fixed& other );
		Fixed& operator-( const Fixed& other );
		Fixed& operator/( const Fixed& other );
		Fixed& operator*( const Fixed& other );

		// Increment / Decrement operators
		Fixed& operator++( int ); 		// i++
		Fixed& operator++( void ); 		// ++i
		Fixed& operator--( int );		// i--
		Fixed& operator++( void );		// --i



		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;
		

};

std::ostream& operator<<(std::ostream& op, Fixed const& nbr);
