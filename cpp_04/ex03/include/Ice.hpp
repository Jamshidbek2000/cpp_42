#ifndef ICE_HPP
#	define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice(Ice const & rhs);
	~Ice();

	Ice&	operator=(Ice const & rhs);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif