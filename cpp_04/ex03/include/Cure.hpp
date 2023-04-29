#ifndef CURE_HPP
#	define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	Cure(Cure const & rhs);
	~Cure();

	Cure&	operator=(Cure const & rhs);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif