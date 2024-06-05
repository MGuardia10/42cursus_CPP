#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T, typename container = std::deque<T> >
class MutantStack: public std::stack<T, container> {
	public:
		/* OCCF */
		MutantStack(): std::stack<T, container>() {};
		MutantStack( const MutantStack& other ) {
			*this = other;
		};
		MutantStack& operator=( const MutantStack& other ) {
			if (this != &other) {
				this->std::stack<T, container>::operator=( other );
			}
			return *this;
		};
		~MutantStack() {};

		typedef typename container::iterator iterator;

		/* Iterator methods */
		iterator begin() {
			return this->c.begin();
		};

		iterator end() {
			return this->c.end();
		};
};
