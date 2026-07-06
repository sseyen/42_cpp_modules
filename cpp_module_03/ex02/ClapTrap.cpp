#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap " <<  _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) {
	*this = other;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
	if (this != &other) {
		_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hit_points == 0 || _energy_points == 0)
    	return ;

	_energy_points -= 1;
	std::cout 
	<< _name << " attacks " 
	<< target << ", causing " 
	<< _attack_damage << " point(s) of damage!" 
	<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_points <= 0 || amount == 0)
		return ;

	_hit_points -= amount;
	if (_hit_points < 0)
		_hit_points = 0;
	std::cout
	<< _name << " takes "
	<< amount << " point(s) of damage!"
	<< std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (amount == 0 || _energy_points == 0 || _hit_points == 0)
		return ;

	_hit_points += amount;
	_energy_points -= 1;
	std::cout
	<< _name << " repairs itself for "
	<< amount << " point(s)!"
	<< std::endl;
}