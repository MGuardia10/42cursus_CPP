#pragma once

#include <iostream>

template<typename T>
typename T::iterator easyfind( T& items, int nbr ) {
	typename T::iterator it = std::find( std::begin(items), std::end(items), nbr );
	if ( it == std::end(items) )
		throw std::runtime_error( "No integer found in the container" );
	
	return it;
}