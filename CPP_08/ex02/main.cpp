#include "MutantStack.hpp"
#include <list>
#include <vector>

int main ( void ) {
	{
		/* Main from subject */
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* comparison with list */
		std::list<int> mList;

		mList.push_front(5);
		mList.push_front(17);

		std::cout << mList.front() << std::endl;
		
		mList.pop_front();
		
		std::cout << mList.size() << std::endl;
		
		mList.push_back(3);
		mList.push_back(5);
		mList.push_back(737);
		mList.push_back(0);

		std::list<int>::iterator it = mList.begin();
		std::list<int>::iterator ite = mList.end();

		++it;
		--it;

		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* Using MutantStack with another container -> Vector */
		MutantStack< int, std::vector<int> > mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack< int, std::vector<int> >::iterator it = mstack.begin();
		MutantStack< int, std::vector<int> >::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}