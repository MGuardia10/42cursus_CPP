#pragma once

#include <iostream>

#define MAX_IDEAS 100

class Brain {

	private:
		std::string ideas[MAX_IDEAS];

	public:
		Brain();
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );
		~Brain();
		
		void	getIdea( int index );
		void	addIdea( std::string idea, int index );
		void	printIdeas( void );
};


