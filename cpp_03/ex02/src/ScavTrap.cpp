#include "../include/ScavTrap.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage =20;
	std::cout << "ScavTrap: " << _name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage =20;
	std::cout << "ScavTrap: " << _name << " was constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << _name << " was destructed" << std::endl;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string & target)
{
	if (_hit_points == 0)
		std::cout << "ScavTrap " << _name << " is dead and cannot attack " << target << std::endl;
	else if (_energy_points == 0)
		std::cout << "ScavTrap " << _name << " has no energy points to attack " << target << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}
