#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_ClatTrap"), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	set_hit_points(FragTrap::get_hit_points());
	set_attack_damage(FragTrap::get_attack_damage());
	set_energy_points(ScavTrap::get_energy_points());
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_trap"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	set_hit_points(FragTrap::get_hit_points());
	set_attack_damage(FragTrap::get_attack_damage());
	set_energy_points(ScavTrap::get_energy_points());
}

DiamondTrap::DiamondTrap(DiamondTrap const & rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = rhs;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::set_name(rhs.ClapTrap::get_name());
		set_name(rhs.get_name());
		set_attack_damage(rhs.get_attack_damage());
		set_energy_points(rhs.get_energy_points());
		set_hit_points(rhs.get_hit_points());
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destructed" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::get_name() << std::endl;
}

void	DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}
