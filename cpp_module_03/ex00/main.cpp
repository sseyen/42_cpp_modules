#include "ClapTrap.hpp"
#include <iostream>

static void print_header(const char* title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void)
{
	print_header("1. Construction / destruction");
	{
		ClapTrap a("Alice");
		ClapTrap b("Bob");
	} // destructors called here

	print_header("2. Basic actions");
	ClapTrap clap("R2-D2");
	clap.attack("Stormtrooper");
	clap.takeDamage(3);
	clap.beRepaired(2);
	clap.attack("Droid");

	print_header("3. Two ClapTraps (attack + manual damage)");
	ClapTrap attacker("Attacker");
	ClapTrap victim("Victim");
	attacker.attack("Victim");
	victim.takeDamage(5); // in ex00 attack does not damage the target — apply damage manually
	victim.beRepaired(3);

	print_header("4. Dead ClapTrap cannot attack/repair");
	ClapTrap dead("Zombie");
	dead.takeDamage(10); // HP -> 0
	dead.attack("anyone");    // should do nothing
	dead.beRepaired(5);       // should do nothing (add HP check in beRepaired)

	print_header("5. No energy");
	ClapTrap tired("Tired");
	for (int i = 0; i < 11; ++i)
		tired.attack("target"); // after 10 attacks energy = 0, 11th should be silent
	tired.beRepaired(1);        // energy = 0, repair should not work

	print_header("6. Copy constructor & assignment");
	ClapTrap original("Original");
	original.takeDamage(4);
	ClapTrap copy(original);
	copy.attack("CopyTarget");

	ClapTrap assigned("Temp");
	assigned = original;
	assigned.beRepaired(1);

	print_header("7. Edge cases");
	ClapTrap edge("Edge");
	edge.takeDamage(0);   // should do nothing
	edge.beRepaired(0);   // should do nothing
	edge.takeDamage(100); // heavy damage

	return 0;
}