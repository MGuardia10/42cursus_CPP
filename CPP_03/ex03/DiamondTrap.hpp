#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string name;

	public:
		DiamondTrap();
		DiamondTrap( std::string _name );
		DiamondTrap( const DiamondTrap& other );
		DiamondTrap& operator=( const DiamondTrap& other );
		~DiamondTrap();

		void		whoAmI( void ) const;
		std::string getName( void ) const;
};
