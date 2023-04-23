#ifndef CLAPTRAP_HPP
#	define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & rhs);
	~ClapTrap();

	std::string get_name(void) const;
	int			get_hit_points(void) const;
	int			get_energy_points(void) const;
	int			get_attack_damage(void) const;

	void		set_name(std::string const & name);
	void		set_hit_points(unsigned int amount);
	void		set_energy_points(unsigned int amount);
	void		set_attack_damage(unsigned int amount);

	ClapTrap&	operator=(ClapTrap const & rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream & operator<<(std::ostream & os, ClapTrap const & obj);


#endif