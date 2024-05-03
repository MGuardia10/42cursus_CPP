#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap( std::string _name );
		ScavTrap( const ScavTrap& other );
		ScavTrap& operator=( const ScavTrap& other );
		~ScavTrap();

		void	attack( const std::string& target );
		void	guardGate( void );
};
