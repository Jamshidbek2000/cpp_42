#ifndef WRONGDOG_HPP
#	define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
private:

protected:

public:
	WrongDog();
	WrongDog(WrongDog const & rhs);
	~WrongDog();

	WrongDog&	operator=(WrongDog const & rhs);

	void	make_sound() const;
};

#endif