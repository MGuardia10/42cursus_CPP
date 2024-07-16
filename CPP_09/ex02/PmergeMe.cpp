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

/* Sort vector */
static std::vector<int>	generate_jacobsthal_sequence_vector( int n ) {
	
	std::vector<int> sequence;
    int j = 1, k = 1;

    while (j < n) {
        sequence.push_back(j);
        int temp = j;
        j = k + j;
        k = temp;
    }

    return sequence;
}

static void binary_insert_vector( std::vector<int> &main_chain, int b ) {
    int left = 0;
    int right = main_chain.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (main_chain[mid] < b)
            left = mid + 1;
        else
            right = mid - 1;
    }

    main_chain.insert(main_chain.begin() + left, b);
}

void	PmergeMe::sortVector( std::vector<int> &arr, int start, int end ) {
	int size = end - start + 1;

	/* Si el tamaño es menor que 2 no se necesita ordenar */
	if ( size < 2 )
		return ;

	/* Si hay un solo elemento, es la "main_chain" */
	if ( size == 2) {
		if ( arr[start] > arr[start + 1] )
			std::swap( arr[start], arr[start + 1] );
		return ;
	}

	/* Agrupar en pares */
	std::vector<int> a, b;
	for (int i = start; i <= end; i += 2) {
		if ( i + 1 <= end ) {
			if ( arr[i] > arr[i + 1] )
				std::swap( arr[i], arr[i + 1] );
			a.push_back( arr[i] );
			b.push_back( arr[i + 1] );
		} else
			b.push_back( arr[i] );
	}

	/* Ordenar recursivamente la cadena principal */
	this->sortVector( a, 0, a.size() - 1 );

	/* Generar la cadena principal */
    std::vector<int> main_chain( a.begin(), a.end() );

	/* Obtener la secuencia de Jacobsthal para minimizar las comparaciones */
	std::vector<int> jacobsthal_seq = generate_jacobsthal_sequence_vector( b.size() );

	/* Insertar elementos de 'b' en la cadena principal siguiendo la secuencia de Jacobsthal */
	for (size_t i = 0; i < b.size(); ++i) {
        if (i < jacobsthal_seq.size()) {
            size_t idx = jacobsthal_seq[i] - 1;
            if (idx < b.size())
                binary_insert_vector( main_chain, b[idx] );
        } else
            binary_insert_vector( main_chain, b[i] );
    }

	 /* Copiar la cadena principal ordenada de vuelta al arreglo original */
    for (size_t i = 0; i < main_chain.size(); ++i)
        arr[start + i] = main_chain[i];
}

/* Sort list */
static std::list<int> generate_jacobsthal_sequence_list( int n ) {
    std::list<int> sequence;
    int j = 1, k = 1;

    while (j < n) {
        sequence.push_back(j);
        int temp = j;
        j = k + j;
        k = temp;
    }

    return sequence;
}

static void binary_insert_list(std::list<int> &main_chain, int b) {
    std::list<int>::iterator it = main_chain.begin();
    std::list<int>::iterator left = main_chain.begin();
    std::list<int>::iterator right = main_chain.end();
    
    while (left != right) {
        it = left;
        std::advance(it, std::distance(left, right) / 2);
        if (*it < b) {
            left = ++it;
        } else {
            right = it;
        }
    }
    
    main_chain.insert(left, b);
}

void	PmergeMe::sortList( std::list<int> &list ) {
	int size = list.size();

	/* Si el tamaño es menor que 2, no se necesita ordenar */
    if (size < 2)
        return ;

    /* Si hay un solo elemento, es la "main_chain" */
    if (size == 2) {
        std::list<int>::iterator it = list.begin();
        int first = *it;
        int second = *(++it);

        if (first > second) {
            list.clear();
            list.push_back( second );
            list.push_back( first );
        }

        return ;
    }

	/* Agrupar en pares */
    std::list<int> a, b;
    std::list<int>::iterator it = list.begin();

    while (it != list.end()) {
        int first = *it;

        it++;
        if (it != list.end()) {
            int second = *it;

            if (first > second)
                std::swap( first, second );
            a.push_back( first );
            b.push_back( second );
            it++;
        } else
            b.push_back( first );
    }

	/* Ordenar recursivamente la cadena principal */
    this->sortList( a );

	/* Generar la cadena principal */
    std::list<int> main_chain( a.begin(), a.end() );

    /* Obtener la secuencia de Jacobsthal para minimizar las comparaciones */
    std::list<int> jacobsthal_seq = generate_jacobsthal_sequence_list( b.size() );

	/* Insertar elementos de 'b' en la cadena principal siguiendo la secuencia de Jacobsthal */
    std::list<int>::iterator b_it = b.begin();
    std::list<int>::iterator j_it = jacobsthal_seq.begin();

    while (b_it != b.end()) {
        if (j_it != jacobsthal_seq.end() && *j_it - 1 < (int)b.size()) {
            int idx = *j_it - 1;
            std::list<int>::iterator temp_it = b.begin();
            std::advance( temp_it, idx );
            binary_insert_list( main_chain, *temp_it );
            j_it++;
        } else
            binary_insert_list( main_chain, *b_it );
        b_it++;
    }

    /* Copiar la cadena principal ordenada de vuelta a la lista original */
    list = main_chain;
}

/* Public methods */
void	PmergeMe::print( dataType type ) {
	int i = 0;

	if ( type == VECTOR ) {
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
	} else if ( type == LIST ) {
		std::list<int>::const_iterator it = myList.begin();

		while ( it != myList.end() ) {
        	if ( i == 4)
				break ;
			std::cout << *it << ' ';
			it++;
			i++;
		}
		
		if ( it == myList.end() )
			std::cout << '\n';
		else
			std::cout << "[...]\n";
	}
}

void	PmergeMe::sort( void ) {
	/* Vector time */
	std::clock_t start = std::clock();
	this->sortVector( myVector, 0, myVector.size() - 1 );
	std::clock_t end = std::clock();
	this->myVectorTime = static_cast<double>(end -start) / CLOCKS_PER_SEC;

	/* List time */
	start = std::clock();
	this->sortList( myList );
	end = std::clock();
	this->myListTime = static_cast<double>(end -start) / CLOCKS_PER_SEC;
}

void	PmergeMe::printTime( void ) {
	/* Vector time */
	std::cout << "Time to process a range of " << myVector.size() << " elements with std::vector :  " << myVectorTime << " s.\n";

	/* List time */
	std::cout << "Time to process a range of " << myList.size() << " elements with std::list   :  " << myListTime << " s.\n";
}
