#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const rawInt) : _value(rawInt << _fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const rawFloat) : _value(roundf(rawFloat * (1 << _fractional_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_value = rhs._value;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const {
	return _value >> _fractional_bits;
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed) {
	out << fixed.toFloat();
	return out;
}
