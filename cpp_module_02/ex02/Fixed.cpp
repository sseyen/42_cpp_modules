#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(int const rawInt) : _value(rawInt << _fractional_bits) {
}

Fixed::Fixed(float const rawFloat) : _value(roundf(rawFloat * (1 << _fractional_bits))) {
}

Fixed::Fixed(Fixed const& other) : _value(other._value) {
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	if (this != &rhs)
		_value = rhs._value;
	return *this;
}

Fixed::~Fixed(void) {
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const {
	return _value >> _fractional_bits;
}

bool Fixed::operator>(Fixed const& other) const {
	return _value > other._value;
}

bool Fixed::operator<(Fixed const& other) const {
	return _value < other._value;
}

bool Fixed::operator>=(Fixed const& other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(Fixed const& other) const {
	return _value <= other._value;
}

bool Fixed::operator==(Fixed const& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(Fixed const& other) const {
	return _value != other._value;
}

Fixed Fixed::operator+(Fixed const& other) const {
	Fixed result;
	result.setRawBits(_value + other._value);
	return result;
}

Fixed Fixed::operator-(Fixed const& other) const {
	Fixed result;
	result.setRawBits(_value - other._value);
	return result;
}

Fixed Fixed::operator*(Fixed const& other) const {
	Fixed result;
	result.setRawBits((static_cast<long>(_value) * other._value) >> _fractional_bits);
	return result;
}

Fixed Fixed::operator/(Fixed const& other) const {
	Fixed result;
	result.setRawBits((static_cast<long>(_value) << _fractional_bits) / other._value);
	return result;
}

Fixed& Fixed::operator++(void) {
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed old = *this;
	_value += 1;
	return old;
}

Fixed& Fixed::operator--(void) {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old = *this;
	_value -= 1;
	return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a._value < b._value) ? a : b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b) {
	return (a._value < b._value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a._value > b._value) ? a : b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
	return (a._value > b._value) ? a : b;
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed) {
	out << fixed.toFloat();
	return out;
}
