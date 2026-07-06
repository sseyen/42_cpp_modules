#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

static void print_header(const char* title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void)
{
	print_header("1. Construction / destruction chain");
	{
		ScavTrap scav("Serena");
	} // ~ScavTrap, then ~ClapTrap

	print_header("2. ScavTrap basic actions");
	ScavTrap scav("Serena");
	scav.attack("intruder");
	scav.takeDamage(30);   // inherited from ClapTrap
	scav.beRepaired(10);   // inherited from ClapTrap
	scav.guardGate();

	print_header("3. ClapTrap vs ScavTrap attack");
	ClapTrap clap("Basic");
	ScavTrap upgraded("Upgraded");
	clap.attack("target");
	upgraded.attack("target");

	print_header("4. Two ScavTraps");
	ScavTrap attacker("Attacker");
	ScavTrap victim("Victim");
	attacker.attack("Victim");
	victim.takeDamage(20);

	print_header("5. Dead ScavTrap");
	ScavTrap dead("Zombie");
	dead.takeDamage(100);
	dead.attack("anyone");    // should do nothing
	dead.beRepaired(5);      // should do nothing
	dead.guardGate();        // still works (subject does not forbid it)

	print_header("6. No energy");
	ScavTrap tired("Tired");
	for (int i = 0; i < 51; ++i)
		tired.attack("target"); // 50 attacks, then energy = 0
	tired.beRepaired(1);        // should do nothing

	print_header("7. Copy constructor & assignment");
	ScavTrap original("Original");
	original.takeDamage(25);
	ScavTrap copy(original);
	copy.attack("CopyTarget");

	ScavTrap assigned("Temp");
	assigned = original;
	assigned.guardGate();

	return 0;
}
