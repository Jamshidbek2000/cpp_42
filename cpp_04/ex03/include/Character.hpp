#ifndef CHARACTER_HPP
#	define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INV_SIZE 4

class Character : public ICharacter
{
private:
	AMateria*	_inventory[INV_SIZE];
	std::string	_name;

public:
	Character(std::string const & name);
	Character(Character const & rhs);
	~Character();

	std::string const & getName() const;

	Character& operator=(Character const & rhs);

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif