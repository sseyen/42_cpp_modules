#include "WrongCat.hpp"
#include <string>
#include <iostream>

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal() {
	_type = "WrongCat";
	std::cout << _type << ": constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << _type << ": destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "* wrong WrongCat noise *" << std::endl;
}


