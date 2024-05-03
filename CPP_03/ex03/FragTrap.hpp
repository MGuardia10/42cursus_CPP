#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap();
		FragTrap( std::string _name );
		FragTrap( const FragTrap& other );
		FragTrap& operator=( const FragTrap& other );
		~FragTrap();

		void	highFivesGuys(void);
};


