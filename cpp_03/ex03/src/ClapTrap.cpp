#include "../include/ClapTrap.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

ClapTrap::ClapTrap() : _name("ClapTrap"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << _name << " was constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destructed" << std::endl;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	ClapTrap::attack(const std::string & target)
{
	if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is dead and cannot attack " << target << std::endl;
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " has no energy points to attack " << target << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	else if (_hit_points < (long)amount)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " was attacked and died" << std::endl;
	}
	else
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " was attacked. Hit points left: " << _hit_points << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is already dead and cannot be repaired" << std::endl;
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " has no energy points to be repaired" << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		_hit_points += amount;
		_energy_points--;
		std::cout << "ClapTrap " << _name << " was repaired. Hit points: " << _hit_points << std::endl;
	}
}
