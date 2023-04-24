#include "../include/DiamondTrap.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

DiamondTrap::DiamondTrap() : ClapTrap("Default_ClatTrap"), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_trap"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::DiamondTrap(DiamondTrap const & rhs)
{
	std::cout << "DiamondTrap " << "copy constructor called" << std::endl;
	*this = rhs;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hit_points = rhs._hit_points;
		_energy_points = rhs._energy_points;
		_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}
