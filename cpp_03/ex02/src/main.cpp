#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int main( void )
{
	ClapTrap harry("Harry");
	ClapTrap hermione("Hermione");
	ClapTrap ron("Ron");
	ScavTrap hagrid("Hagrid");
	FragTrap snape("Pr. Snape");

	harry.attack("Voldemort");
	harry.attack("Malfoy");
	harry.attack("Draco");
	harry.takeDamage(5);
	hermione.takeDamage(9);
	hermione.takeDamage(10);
	ron.beRepaired(10);
	ron.takeDamage(19);
	hagrid.attack("Voldemort");
	hagrid.takeDamage(99);
	hagrid.beRepaired(50);
	hagrid.guardGate();
	snape.attack("Voldemort");
	snape.takeDamage(99);
	snape.beRepaired(50);
	snape.highFivesGuys();
	return (0); 
}
