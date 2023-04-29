#ifndef AMATERIA_HPP
#	define AMATERIA_HPP

#include <iostream>

class ICharacter; // Forward declaration

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const & rhs);
	virtual ~AMateria();

	AMateria & operator=(AMateria const & rhs);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif