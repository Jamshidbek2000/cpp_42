#ifndef ANIMAL_HPP
#	define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string const & type);
	Animal(Animal const & rhs);
	virtual ~Animal();

	Animal&	operator=(Animal const & rhs);

	virtual void	make_sound() const;
};

#endif