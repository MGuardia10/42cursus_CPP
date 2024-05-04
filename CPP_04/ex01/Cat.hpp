#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {

	private:
		Brain *brain;

	public:
		Cat();
		Cat( const Cat& other );
		Cat& operator=( const Cat& other );
		~Cat();

		void	makeSound( void ) const;
		void	addIdea( std::string idea, int index );
		void	getIdea( int index ) const;

};