#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif // SCAVTRAP_HPP