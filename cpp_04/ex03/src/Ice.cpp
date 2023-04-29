#include "../include/Ice.hpp"
#include "../include/Character.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor is called" << std::endl;
}

Ice::Ice(Ice const & rhs) : AMateria(rhs)
{
	// std::cout << "Ice copy constructor is called" << std::endl;
	*this = rhs;
}

Ice::~Ice()
{
	// std::cout << "Ice is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Ice&	Ice::operator=(Ice const & rhs)
{
	(void)rhs;
	// std::cout << "Ice assignment operator is called" << std::endl;
	_type = rhs._type;
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout <<" shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
