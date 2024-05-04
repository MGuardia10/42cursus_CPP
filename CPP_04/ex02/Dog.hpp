#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {

	private:
		Brain *brain;

	public:
		Dog();
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );
		~Dog();

		void	makeSound( void ) const;
		void	addIdea( std::string idea, int index );
		void	getIdea( int index ) const;

};