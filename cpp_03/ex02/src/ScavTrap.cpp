#include "../include/ScavTrap.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	set_hit_points(100);
	set_energy_points(50);
	set_attack_damage(20);
	std::cout << "ScavTrap: " << get_name() << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	set_hit_points(100);
	set_energy_points(50);
	set_attack_damage(20);
	std::cout << "ScavTrap: " << get_name() << " was constructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = rhs;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << get_name() << " was destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		set_name(rhs.get_name());
		set_hit_points(rhs.get_energy_points());
		set_energy_points(rhs.get_energy_points());
		set_attack_damage(rhs.get_attack_damage());
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string & target)
{
	if (get_hit_points() == 0)
		std::cout << "ScavTrap " << get_name() << " is dead and cannot attack " << target << std::endl;
	else if (get_energy_points() == 0)
		std::cout << "ScavTrap " << get_name() << " has no energy points to attack " << target << std::endl;
	else if (get_energy_points() > 0 && get_hit_points() > 0)
	{
		std::cout << "ScavTrap " << get_name() << " attacks " << target;
		std::cout << " causing " << get_attack_damage() << " damage" << std::endl;
		set_energy_points(get_energy_points() - 1);
	}
}
