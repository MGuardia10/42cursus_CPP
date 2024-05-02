#pragma once

#include <iostream>
#include <string>

class	ClapTrap {
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	
	public:
		ClapTrap();
		ClapTrap( std::string _name );
		ClapTrap( const ClapTrap& other );
		ClapTrap& operator=( const ClapTrap& other );
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName( void ) const;
		unsigned int	getHP( void ) const;
		unsigned int	getEP( void ) const;
		unsigned int	getAD( void ) const;

		void	setName( std::string name );
		void	setHP( unsigned int hitPoints );
		void	setEP( unsigned int energyPoints );
		void	setAD( unsigned int attackDamage );
};
