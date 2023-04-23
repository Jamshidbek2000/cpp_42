#include "../include/FragTrap.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	set_hit_points(100);
	set_energy_points(100);
	set_attack_damage(30);
	std::cout << "FragTrap: " << get_name() << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	set_hit_points(100);
	set_energy_points(100);
	set_attack_damage(30);
	std::cout << "FragTrap: " << get_name() << " was constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << get_name() << " was destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

FragTrap&	FragTrap::operator=(FragTrap const & rhs)
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey guys, I'm " << get_name() << ". Shall we have highfives?" << std::endl;
}

void	FragTrap::attack(const std::string & target)
{
	if (get_hit_points() == 0)
		std::cout << "FragTrap " << get_name() << " is dead and cannot attack " << target << std::endl;
	else if (get_energy_points() == 0)
		std::cout << "FragTrap " << get_name() << " has no energy points to attack " << target << std::endl;
	else if (get_energy_points() > 0 && get_hit_points() > 0)
	{
		std::cout << "FragTrap " << get_name() << " attacks " << target;
		std::cout << " causing " << get_attack_damage() << " damage" << std::endl;
		set_energy_points(get_energy_points() - 1);
	}
}
