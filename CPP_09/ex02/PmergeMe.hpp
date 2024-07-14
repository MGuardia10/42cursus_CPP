#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe {
	private:
		std::vector<int> myVector;
		std::list<int> myList;
		double myVectorTime;
		double myListTime;

		class InvalidInputException : public std::exception {
			const char* what() const throw() {
				return "Only positive integers are valid";
			}
		};

		class MaxIntException : public std::exception {
			const char* what() const throw() {
				return "Numbers must fit in an INT data type";
			}
		};

	public:
		/* OCCF */
		PmergeMe();
		PmergeMe( char **argv );
		// PmergeMe( const PmergeMe& other );
		// PmergeMe& operator=( const PmergeMe& other );
		~PmergeMe();

		/* Public methods */
		void	print( void );
		void	sort( void );
		void	printTime( void );
		void	setContainers( char **argv );

};