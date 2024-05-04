#pragma once

#include <iostream>

class	Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal( const Animal& other );
		Animal& operator=( const Animal& other );
		virtual ~Animal();

		std::string	getType( void ) const;
		virtual void		makeSound( void ) const;

};
