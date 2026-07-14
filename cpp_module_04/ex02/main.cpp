#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "TEST 1 | Animal is abstract" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Animal a;           // compile error" << std::endl;
	// Animal a;
	std::cout << "new Animal();       // compile error" << std::endl;
	// Animal *p = new Animal();
	std::cout << "only Dog / Cat work" << std::endl;

	std::cout << std::endl;
	std::cout << "TEST 2 | delete through Animal*" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Dog | type : " << dog->getType() << std::endl;
	std::cout << "Dog | sound: ";
	dog->makeSound();

	std::cout << "Cat | type : " << cat->getType() << std::endl;
	std::cout << "Cat | sound: ";
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
}
