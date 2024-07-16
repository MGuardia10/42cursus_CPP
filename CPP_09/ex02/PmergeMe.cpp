#include "PmergeMe.hpp"

/* OCCF */
PmergeMe::PmergeMe() : myVector(), myList(), myVectorTime(0), myListTime(0) {}
PmergeMe::PmergeMe(char **argv) : myVectorTime(0), myListTime(0) {
	this->setContainers( argv );
}
PmergeMe::PmergeMe( const PmergeMe& other ) { *this = other; }
PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
	if (this != &other) {
		this->myList = other.myList;
		this->myVector = other.myVector;
		this->myVectorTime = other.myVectorTime;
		this->myListTime = other.myListTime;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

/* Exceptions */
const char* PmergeMe::InvalidInputException::what() const throw() {
	return "Only positive integers are valid.";
}

const char* PmergeMe::MaxIntException::what() const throw() {
	return "Numbers must fit in an INT data type.";
}

/* Private Methods */
void	PmergeMe::setContainers( char **argv ) {

	int i = 1;
	char *inputEnd = NULL;

	while ( argv[i] ) {
		long nbr = strtol(argv[i], &inputEnd, 10);

		if (inputEnd[0] || nbr < 0)
			throw PmergeMe::InvalidInputException();

		if (nbr > INT_MAX)
			throw PmergeMe::MaxIntException();
		
		myVector.push_back( static_cast<int>(nbr) );
		myList.push_back( static_cast<int>(nbr) );

		i++;
	}
}

void	PmergeMe::sortVector( void ) {

}

void	PmergeMe::sortList( void ) {
	
}

/* Public methods */
void	PmergeMe::print( void ) {
	int i = 0;

	while ( myVector[i] && i != 4 ) {
		std::cout << myVector[i] << ' ';
		i++;
	}

	if (!myVector[i]) {
		std::cout << '\n';
		return ;
	} 
	
	if (myVector.size() == 5) {
		std::cout << myVector[i] << '\n';
	} else {
		std::cout << "[...]\n";
	}
}

void	PmergeMe::sort( void ) {
	/* Vector time */
	std::clock_t start = std::clock();
	this->sortVector();
	std::clock_t end = std::clock();
	this->myVectorTime = static_cast<double>(end -start) / CLOCKS_PER_SEC;

	/* List time */
	start = std::clock();
	this->sortList();
	end = std::clock();
	this->myListTime = static_cast<double>(end -start) / CLOCKS_PER_SEC;
}

void	PmergeMe::printTime( void ) {
	/* Vector time */
	std::cout << "Time to process a range of " << myVector.size() << " elements with std::vector :  " << myVectorTime << " s.\n";

	/* List time */
	std::cout << "Time to process a range of " << myList.size() << " elements with std::list   :  " << myListTime << " s.\n";
}
