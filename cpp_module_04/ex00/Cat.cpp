#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

// Default constructor
Cat::Cat(void) : Animal() {
	_type = "Cat";
	std::cout << "Cat: constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat: destructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}
