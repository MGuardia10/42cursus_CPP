#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <ctime>

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
		void	sortVector( void );
		void	sortList( void );

	public:
		/* OCCF */
		PmergeMe();
		PmergeMe( char **argv );
		PmergeMe( const PmergeMe& other );
		PmergeMe& operator=( const PmergeMe& other );
		~PmergeMe();

		/* Public methods */
		void	print( void );
		void	sort( void );
		void	printTime( void );
};