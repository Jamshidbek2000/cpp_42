#ifndef WRONGCAT_HPP
#	define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat const & rhs);
	~WrongCat();

	WrongCat&	operator=(WrongCat const & rhs);

	void	make_sound() const;
};

#endif