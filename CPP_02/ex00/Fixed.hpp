#pragma once

#include <iostream>

class	Fixed {

	private:
		int					_rawBits;
		static int const	_fractionalBits;

	public:
		Fixed();
		Fixed( const Fixed& copy );
		Fixed& operator=( const Fixed& otra );
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};