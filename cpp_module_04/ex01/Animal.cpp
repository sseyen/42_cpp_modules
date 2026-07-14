#include "Animal.hpp"
#include <string>
#include <iostream>

// Default constructor
Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal: constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal: destructor called" << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "* undefined animal noise *" << std::endl;
}

std::string Animal::getType(void) const {
	return (_type);
}
