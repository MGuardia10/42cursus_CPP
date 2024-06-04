#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	private:

	public:
		/* OCCF */
		MutantStack(): std::stack<T>() {};
		MutantStack( const MutantStack& other ) {
			*this = other;
		};
		MutantStack& operator=( const MutantStack& other ) {
			if (this != &other) {
				this->std::stack<T>::operator=( other );
			}

			return *this;
		};
		~MutantStack() {};

		typedef typename std::deque<T>::iterator iterator;

		/* Iterator methods */
		iterator begin( void ) {
			return this->c.begin();
		};

		iterator end( void ) {
			return this->c.end();
		};
};

// std::ostream& operator<<( std::ostream &op, MutantStack<int>& obj ) {

// 	MutantStack<int>::iterator it = obj.begin();
// 	MutantStack<int>::iterator ite = obj.end();

// 	op << "[ ";
// 	while( it != ite ) {
// 		op << *it << ' ';
// 		it++;
// 	}
// 	op << "]";

// 	return op; 
// };