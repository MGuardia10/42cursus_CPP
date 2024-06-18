#include "easyfind.hpp"

/* Array & forward_list are c++11 containers */
int main( void ) {
	{
		/* Vector */
		try {
			int arr[] = {8, 4, 5, 9, 17, 86};
			std::vector<int> myVector(arr, arr+ sizeof(arr) / sizeof(arr[0]));

			std::vector<int>::iterator it = easyfind(myVector, 86);
			std::cout << "Found element: " << *it << std::endl;

		} catch (std::exception & e) {
			std::cout << "Caught exception: " << e.what() << '\n';
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* List -> doubly-linked list */
		try {
			int arr[] = {8, 4, 5, 9, 17, 86};
			std::list<int> myList(arr, arr + sizeof(arr) / sizeof(arr[0]));

			std::list<int>::iterator it = easyfind(myList, 4);
			std::cout << "Found element: " << *it << std::endl;

		} catch (std::exception & e) {
			std::cout << "Caught exception: " << e.what() << '\n';
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* deque -> double-ended queue */
		try {
			int arr[] = {8, 4, 5, 9, 17, 86};
			std::deque<int> myDeque(arr, arr + sizeof(arr) / sizeof(arr[0]));

			std::deque<int>::iterator it = easyfind(myDeque, 8);
			std::cout << "Found element: " << *it << std::endl;

		} catch (std::exception & e) {
			std::cout << "Caught exception: " << e.what() << '\n';
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* Error example */
		try {
			int arr[] = {8, 4, 5, 9, 17, 86};
			std::vector<int> myVector(arr, arr + sizeof(arr) / sizeof(arr[0]));

			std::vector<int>::iterator it = easyfind(myVector, 1241354);
			std::cout << "Found element: " << *it << std::endl;

		} catch (std::exception & e) {
			std::cout << "Caught exception: " << e.what() << '\n';
		}
	}

	return 0;
}