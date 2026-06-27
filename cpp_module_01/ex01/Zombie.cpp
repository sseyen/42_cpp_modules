#include "Zombie.hpp"

Zombie::Zombie() : _name("") {
}

Zombie::Zombie(const std::string& name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << ": is destroyed." << std::endl;
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
	_name = name;
}
