#include "../includes/Weapon.hpp"

// ************************************************************************** //
//                               CONSTRUCTOR/DESTRUCTOR                                      //
// ************************************************************************** //

Weapon::Weapon(void): _type(""){}
Weapon::Weapon(std::string type): _type(type){}
Weapon::~Weapon(void) {}

// ************************************************************************** //
//                               SETTERS/GETTERS                              //
// ************************************************************************** //

void	Weapon::setType(std::string type)
{
	_type = type;
}

const std::string&	Weapon::getType(void) const
{
	return (_type);
}
