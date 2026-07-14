#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

// Default constructor
Dog::Dog(void) : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog: constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		delete _brain;
		_brain = new Brain(*other._brain);
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog: destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
	
}

Brain* Dog::getBrain(void) const {
	return (_brain);
}
