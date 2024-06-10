#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

static Base* generate(void) {
	int randomNumber = rand() % 3 + 1;

    if (randomNumber == 1) {
		std::cout << "A generated\n";
        return new A();
    } else if (randomNumber == 2) {
		std::cout << "B generated\n";
        return new B();
    } else {
		std::cout << "C generated\n";
        return new C();
    }
}
static void identify(Base* p) {
	std::cout << "Identify with pointer: ";
	if (dynamic_cast<A*>( p ))
		std::cout << "Pointer is type A\n";
	else if (dynamic_cast<B*>( p ))
		std::cout << "Pointer is type B\n";
	else if (dynamic_cast<C*>( p ))
		std::cout << "Pointer is type C\n";
	else
		std::cout << "Cannot identify pointer type\n";
}

static void identify(Base& p) {
	std::cout << "Identify with reference: ";
	try {
		A &a = dynamic_cast<A&>( p );
		std::cout << "Reference is type A\n";
		(void)a;
		return ;
	} catch (const std::bad_cast & e) {}

	try {
		B &b = dynamic_cast<B&>( p );
		std::cout << "Reference is type B\n";
		(void)b;
		return ;
	} catch (const std::bad_cast & e) {}

	try {
		C &c = dynamic_cast<C&>( p );
		std::cout << "Reference is type C\n";
		(void)c;
		return ;
	} catch (const std::bad_cast & e) {}
	
	std::cout << "Cannot identify reference type\n";
}


int main( void ) {
	srand(static_cast<unsigned int>(time(NULL)));
	{
		/* Generate random instance of A, B or C */
		Base *a = generate();

		/* Identify with pointer */
		identify( a );

		/* Identify with reference */
		identify( *a );

		delete a;
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Try with Base type */
		Base  *a = new Base();

		/* Identify with pointer */
		identify( a );

		/* Identify with reference */
		identify( *a );

		delete a;
	}

	return 0;
}