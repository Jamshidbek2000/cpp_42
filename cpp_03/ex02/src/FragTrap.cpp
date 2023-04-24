#include "../include/FragTrap.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap: " << _name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap: " << _name << " was constructed" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << _name << " was destructed" << std::endl;
}


// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey guys, I'm " << _name << ". Shall we have highfives?" << std::endl;
}

void	FragTrap::attack(const std::string & target)
{
	if (_hit_points == 0)
		std::cout << "FragTrap " << _name << " is dead and cannot attack " << target << std::endl;
	else if (_energy_points == 0)
		std::cout << "FragTrap " << _name << " has no energy points to attack " << target << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}
