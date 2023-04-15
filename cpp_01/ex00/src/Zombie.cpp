#include "../includes/Zombie.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Zombie::Zombie(void) : _name(""){}

Zombie::Zombie(std::string name) : _name(name){}

Zombie::~Zombie(void)
{
	std::cout << _name << " is destructed" << std::endl;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
