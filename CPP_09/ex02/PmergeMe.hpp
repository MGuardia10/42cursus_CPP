#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <ctime>

typedef enum dataType {
	VECTOR,
	LIST
} dataType;

class PmergeMe {
	private:
		std::vector<int> myVector;
		std::list<int> myList;
		double myVectorTime;
		double myListTime;

		/* Exceptions */
		class InvalidInputException : public std::exception {
			const char* what() const throw();
		};

		class MaxIntException : public std::exception {
			const char* what() const throw();
		};

		/* Private methods */
		void	setContainers( char **argv );
		void	sortVector( std::vector<int> &arr, int start, int end );
		void	sortList( std::list<int> &list );

	public:
		/* OCCF */
		PmergeMe();
		PmergeMe( char **argv );
		PmergeMe( const PmergeMe& other );
		PmergeMe& operator=( const PmergeMe& other );
		~PmergeMe();

		/* Public methods */
		void	print( dataType type );
		void	sort( void );
		void	printTime( void );
};