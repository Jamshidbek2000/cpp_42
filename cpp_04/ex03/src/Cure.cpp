#include "../include/Cure.hpp"
#include "../include/Character.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor is called" << std::endl;
}

Cure::Cure(Cure const & rhs) : AMateria(rhs)
{
	// std::cout << "Cure copy constructor is called" << std::endl;
	*this = rhs;
}

Cure::~Cure()
{
	// std::cout << "Cure is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Cure&	Cure::operator=(Cure const & rhs)
{
	(void)rhs;
	// std::cout << "Cure assignment operator is called" << std::endl;
	_type = rhs._type;
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << " heals " << target.getName() << "'s wounds *" << std::endl;
}
