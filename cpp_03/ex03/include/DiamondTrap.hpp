#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <stdio.h>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;

public:
	DiamondTrap();
	DiamondTrap(std::string const & name);
	DiamondTrap(DiamondTrap const & rhs);
	~DiamondTrap();

	DiamondTrap&	operator=(DiamondTrap const & rhs);

	void attack(const std::string & target);
    void whoAmI();
};

#endif