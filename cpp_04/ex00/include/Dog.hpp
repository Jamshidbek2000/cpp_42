#ifndef DOG_HPP
#	define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog const & rhs);
	virtual ~Dog();

	Dog&	operator=(Dog const & rhs);

	virtual void	make_sound() const;
};

#endif