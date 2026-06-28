#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
private:
	int _value;
	static const int _fractional_bits = 8;

public:
	Fixed();
	Fixed(int const rawInt);
	Fixed(float const rawFloat);
	Fixed(Fixed const& other);
	Fixed& operator=(Fixed const& rhs);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif
