#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

// Default constructor
WrongAnimal::WrongAnimal(void) {
	_type = "WrongAnimal";
	std::cout << _type << ": constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << _type << ": destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "* wrong WrongAnimal noise *" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (_type);
}
