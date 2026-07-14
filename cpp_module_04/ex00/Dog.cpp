#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

// Default constructor
Dog::Dog(void) : Animal() {
	_type = "Dog";
	std::cout << "Dog: constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog: destructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
	
}