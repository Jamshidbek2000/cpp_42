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

ClapTrap::ClapTrap(ClapTrap const & rhs)
{
	std::cout << "ClapTrap " << "Copy constructor called" << std::endl;
	*this = rhs;

}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destructed" << std::endl;
}

// ************************************************************************** //
//                               SETTERS/GETTERS                              //
// ************************************************************************** //

std::string	ClapTrap::get_name(void) const {return (_name);}
int			ClapTrap::get_hit_points(void) const {return (_hit_points);}
int			ClapTrap::get_energy_points(void) const {return (_energy_points);}
int			ClapTrap::get_attack_damage(void) const {return (_attack_damage);}

void		ClapTrap::set_name(std::string const & name){_name = name;}
void		ClapTrap::set_hit_points(unsigned int amount){_hit_points = amount;}
void		ClapTrap::set_energy_points(unsigned int amount){_energy_points = amount;}
void		ClapTrap::set_attack_damage(unsigned int amount){_attack_damage = amount;}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

std::ostream & operator<<(std::ostream & os, ClapTrap const & obj)
{
	os << "Name: " << obj.get_name() << std::endl;
	os << "Hit points: " << obj.get_hit_points() << std::endl;
	os << "Energy points: " << obj.get_energy_points() << std::endl;
	os << "Attack damage: " << obj.get_attack_damage() << std::endl;

	return (os);
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs.get_name();
		_hit_points = rhs.get_energy_points();
		_energy_points = rhs.get_energy_points();
		_attack_damage = rhs.get_attack_damage();
	}
	return (*this);
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
