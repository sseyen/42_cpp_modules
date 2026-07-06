#include "ScavTrap.hpp"
#include <iostream>
#include <string>

// Default constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
	std::cout << "ScavTrap " <<  _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hit_points == 0 || _energy_points == 0)
        return;

    _energy_points -= 1;
    std::cout << "ScavTrap " << _name << " fiercely attacks "
              << target << ", causing " << _attack_damage
              << " point(s) of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}