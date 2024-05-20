#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		/* Pholymorphism Test */
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << meta->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		
		meta->makeSound();
		j->makeSound();
		i->makeSound(); //will output the cat sound

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Wrong Classes */
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		const WrongCat* k = new WrongCat();
		
		std::cout << meta->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << k->getType() << std::endl;
		
		meta->makeSound();
		j->makeSound();
		i->makeSound(); //will output the animal sound (no sound)
		k->makeSound();

		delete meta;
		delete j;
		delete i;
		delete k;
	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Orthodox Canonical Form Class Test */
		Animal *a = new Cat();
		Animal *b = new Dog();
		Animal c;
		c = *a;
		Animal d( *b );

		std::cout << a->getType() << ": ";
		a->makeSound();

		std::cout << b->getType() << ": ";
		b->makeSound();

		std::cout << c.getType() << ": ";
		c.makeSound(); // no sound

		std::cout << d.getType() << ": ";
		d.makeSound(); // no sound

		std::cout << &a << std::endl;
		std::cout << &b << std::endl;
		std::cout << &c << std::endl;
		std::cout << &d << std::endl;

		delete a;
		delete b;

	}
	std::cout << "\n------------------------------------------------------------\n\n";
	{
		/* Dog and Cat classes test */
		Dog a;
		Cat b;

		std::cout << "a type: " << a.getType() << std::endl;
		std::cout << "b type: " << b.getType() << std::endl;

		a.makeSound();
		b.makeSound();
	}
	
	return 0;
}