#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:
		FragTrap();
		FragTrap( std::string _name );
		FragTrap( const FragTrap& other );
		FragTrap& operator=( const FragTrap& other );
		~FragTrap();

		void	attack( const std::string& target );
		void	highFivesGuys(void);
};


