#include "../includes/HumanB.hpp"

// ************************************************************************** //
//                               CONSTRUCTOR/DESTRUCTOR                                      //
// ************************************************************************** //

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}
HumanB::~HumanB(void){}

// ************************************************************************** //
//                               SETTERS/GETTERS                              //
// ************************************************************************** //

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

// ************************************************************************** //
//                               Rest                                         //
// ************************************************************************** //

void	HumanB::attack(void) const
{
	if (_weapon == NULL)
		std::cout << _name << " doesn't have weapon yet, but you can set it" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
