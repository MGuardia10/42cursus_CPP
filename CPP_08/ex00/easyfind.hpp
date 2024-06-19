#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template<typename T>
typename T::iterator easyfind( T& items, int nbr ) {
	typename T::iterator it = std::find( items.begin(), items.end(), nbr );
	if ( it == items.end() )
		throw std::runtime_error( "No integer found in the container" );
	
	return it;
}