#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

// Default constructor
Cat::Cat(void) : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat: constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		delete _brain;
		_brain = new Brain(*other._brain);
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat: destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return (_brain);
}
