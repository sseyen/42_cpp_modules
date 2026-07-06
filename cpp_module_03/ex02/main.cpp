#include "FragTrap.hpp"
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
		FragTrap frag("Fraggy");
	} // ~FragTrap, then ~ClapTrap

	print_header("2. FragTrap basic actions");
	FragTrap frag("Fraggy");
	frag.attack("intruder");       // inherited ClapTrap::attack, damage 30
	frag.takeDamage(40);
	frag.beRepaired(15);
	frag.highFivesGuys();

	print_header("3. ClapTrap vs FragTrap attack");
	ClapTrap clap("Basic");
	FragTrap upgraded("Upgraded");
	clap.attack("target");         // 0 damage
	upgraded.attack("target");     // 30 damage

	print_header("4. Two FragTraps");
	FragTrap attacker("Attacker");
	FragTrap victim("Victim");
	attacker.attack("Victim");
	victim.takeDamage(30);

	print_header("5. Dead FragTrap");
	FragTrap dead("Zombie");
	dead.takeDamage(100);
	dead.attack("anyone");         // should do nothing
	dead.beRepaired(5);            // should do nothing
	dead.highFivesGuys();          // still works

	print_header("6. No energy");
	FragTrap tired("Tired");
	for (int i = 0; i < 101; ++i)
		tired.attack("target");    // 100 attacks, then energy = 0
	tired.beRepaired(1);           // should do nothing

	print_header("7. Copy constructor & assignment");
	FragTrap original("Original");
	original.takeDamage(25);
	FragTrap copy(original);
	copy.attack("CopyTarget");

	FragTrap assigned("Temp");
	assigned = original;
	assigned.highFivesGuys();

	return 0;
}
