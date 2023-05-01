#ifndef AANIMAL_HPP
#	define AANIMAL_HPP

#include <iostream>

class AAnimal
{
private:
	AAnimal();
	AAnimal(AAnimal const & rhs);
	AAnimal&	operator=(AAnimal const & rhs);

protected:
	std::string type;
	AAnimal(std::string const & type);

public:
	virtual ~AAnimal();
	virtual void	make_sound() const = 0;
};

#endif