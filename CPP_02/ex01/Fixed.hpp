#pragma once

#include <iostream>

class	Fixed {

	private:
		int					_rawBits;
		static int const	_fractionalBits;

	public:
		Fixed();
		Fixed( const int nbr );
		Fixed( const float nbr );
		Fixed( const Fixed& copy );
		Fixed& operator=( const Fixed& copy );
		~Fixed();

		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;

};

std::ostream& operator<<(std::ostream& o, Fixed const& nbr);