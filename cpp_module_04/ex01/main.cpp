#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "TEST 1 | delete through Animal*" << std::endl;
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

	std::cout << std::endl;
	std::cout << "TEST 2 | array of Animals" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	const int size = 4;
	Animal* zoo[size];

	zoo[0] = new Dog();
	zoo[1] = new Dog();
	zoo[2] = new Cat();
	zoo[3] = new Cat();

	for (int i = 0; i < size; i++)
	{
		std::cout << "zoo[" << i << "] | "
		          << zoo[i]->getType() << " | sound: ";
		zoo[i]->makeSound();
	}

	for (int i = 0; i < size; i++)
		delete zoo[i];

	std::cout << std::endl;
	std::cout << "TEST 3 | deep copy" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	Dog original;
	Dog by_ctor(original);
	Dog by_assign;
	by_assign = original;

	std::cout << "original | brain: " << original.getBrain() << std::endl;
	std::cout << "by_ctor  | brain: " << by_ctor.getBrain() << std::endl;
	std::cout << "by_assign| brain: " << by_assign.getBrain() << std::endl;

	if (original.getBrain() != by_ctor.getBrain()
		&& original.getBrain() != by_assign.getBrain())
		std::cout << "=> deep copy (different brain addresses)" << std::endl;
	else
		std::cout << "=> shallow copy FAIL" << std::endl;

	std::cout << std::endl;

	return 0;
}
