#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "=== Polymorphism (virtual) ===" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Copy ===" << std::endl;

	Dog original;
	Dog copy(original);

	std::cout << "original type: " << original.getType() << std::endl;
	std::cout << "copy type:     " << copy.getType() << std::endl;
	original.makeSound();
	copy.makeSound();

	std::cout << "\n=== Wrong polymorphism (no virtual) ===" << std::endl;

	const WrongAnimal* wrong = new WrongCat();

	std::cout << "wrong type: " << wrong->getType() << std::endl;
	wrong->makeSound();

	std::cout << "\n=== WrongCat directly ===" << std::endl;

	WrongCat wc;
	wc.makeSound();

	delete wrong;

	return 0;
}
