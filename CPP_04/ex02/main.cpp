#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal a;
	Dog	dog;
	Cat	cat;

	dog.makeSound();
	cat.makeSound();

	dog.addIdea( "Dog new Idea", 0 );
	cat.addIdea( "Cat new Idea", 0 );

	dog.getIdea( 0 );
	cat.getIdea( 0 );
	
	return 0;
}