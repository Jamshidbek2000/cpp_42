#ifndef AANIMAL_HPP
#	define AANIMAL_HPP

#include <iostream>

class AAnimal
{
private:

protected:
	std::string type;

public:
	AAnimal();
	AAnimal(std::string const & type);
	AAnimal(AAnimal const & rhs);
	virtual ~AAnimal();

	AAnimal&	operator=(AAnimal const & rhs);

	virtual void	make_sound() const = 0;
};

#endif