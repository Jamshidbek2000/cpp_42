#ifndef CAT_HPP
#	define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:

protected:

public:
	Cat();
	Cat(Cat const & rhs);
	virtual ~Cat();

	Cat&	operator=(Cat const & rhs);

	virtual void	make_sound() const;
};

#endif