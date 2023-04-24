#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_ClatTrap"), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_hit_points = FragTrap::_hit_points;
	_attack_damage = FragTrap::_attack_damage;
	_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_trap"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	_hit_points = FragTrap::_hit_points;
	_attack_damage = FragTrap::_attack_damage;
	_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destructed" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}
