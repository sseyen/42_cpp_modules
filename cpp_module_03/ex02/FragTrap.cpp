#include "FragTrap.hpp"
#include <iostream>

// Default constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
	std::cout << "FragTrap " <<  _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests positive high fives!" << std::endl;
}