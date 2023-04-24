#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

	void guardGate(void);
	void attack(const std::string & target);
};


#endif