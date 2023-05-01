#include "../include/Character.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Character::Character(std::string const & name) : _name(name)
{
	// std::cout << name << " Character is constructed" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
	
}

Character::Character(Character const & rhs)
{
	// std::cout << "Copy constructor is called" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
	*this = rhs;
}

Character::~Character()
{
	// std::cout << _name << " is destructed" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Character& Character::operator=(Character const & rhs)
{
	// std::cout << "Character assignment operator is called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs.getName();
		for (size_t i = 0; i < INV_SIZE; i++)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			if (rhs._inventory[i] != NULL)
			{
				_inventory[i] = rhs._inventory[i]->clone();
				// std::cout << "copied: " << _inventory[i]->getType() << std::endl;
			}
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string const & Character::getName() const {return (_name);}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Equipment is NULL" << std::endl;
		return ;
	}
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (_inventory[i] == NULL)
		{
			std::cout << _name << " added " << m->getType() << " to inventory" << std::endl;
			_inventory[i] = m;
			return ;
		}
		if (_inventory[i] == m)
		{
			std::cout << _name << " already has " << m->getType() << " in inventory" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= INV_SIZE)
		std::cout << "Index is too big" << std::endl;
	else if (_inventory[idx] == NULL)
		std::cout << _name << " doesn't have Equipment #" << idx << "!" << std::endl;
	else
	{
		_inventory[idx] = NULL;
		std::cout << "Equipment #" << idx << " has been thrown away" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= INV_SIZE)
		std::cout << "Index is too big" << std::endl;
	else if (_inventory[idx] == NULL)
		std::cout << "Equipment #" << idx << " was not found" << std::endl;
	else
	{
		std::cout << "* " << _name;
		_inventory[idx]->use(target);
	}
}
