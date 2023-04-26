#ifndef WRONGANIMAL_HPP
#	define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
private:

protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string const & type);
	WrongAnimal(WrongAnimal const & rhs);
	~WrongAnimal();

	WrongAnimal&	operator=(WrongAnimal const & rhs);

	void	make_sound() const;
};

#endif