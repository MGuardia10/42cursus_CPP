#pragma once

#include <iostream>

class	Fixed {

	private:
		int					rawBits;
		static int const	fractionalBits;

	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};