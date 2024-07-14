#include "PmergeMe.hpp"

/* OCCF */
PmergeMe::PmergeMe() : myVector(), myList(), myVectorTime(0), myListTime(0) {}
PmergeMe::PmergeMe(char **argv) : myVectorTime(0), myListTime(0) {
	this->setContainers( argv );
}
// PmergeMe::PmergeMe( const PmergeMe& other ) {}
// PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {}
PmergeMe::~PmergeMe() {}

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

	for (int i = 0; i < 1000000; ++i) {
        // Simulación de trabajo
    }

	std::clock_t end = std::clock();
	this->myVectorTime = static_cast<double>(end -start);

	/* List time */
	start = std::clock();

	for (int i = 0; i < 1000000; ++i) {
        // Simulación de trabajo
    }

	end = std::clock();
	this->myListTime = static_cast<double>(end -start);
}

void	PmergeMe::printTime( void ) {
	/* Vector time */
	std::cout << "Time to process a range of " << myVector.size() << " elements with std::vector :  " << myVectorTime << " us.\n";

	/* List time */
	std::cout << "Time to process a range of " << myList.size() << " elements with std::list   :  " << myListTime << " us.\n";
}

void	PmergeMe::setContainers( char **argv ) {

	int i = 1;
	char *inputEnd = NULL;

	while ( argv[i] ) {
		long nbr = strtol(argv[i], &inputEnd, 10);

		if (inputEnd[0])
			throw PmergeMe::InvalidInputException();

		if (nbr < 0 || nbr > INT_MAX)
			throw PmergeMe::MaxIntException();
		
		myVector.push_back( static_cast<int>(nbr) );
		myList.push_back( static_cast<int>(nbr) );

		i++;
	}
}