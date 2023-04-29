#include "../include/AMateria.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

AMateria::AMateria()
{
	// std::cout << "AMateria default constructor is called" << std::endl;
	_type = "Mystary";
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "AMateria string constructor is called" << std::endl;
}

AMateria::AMateria(AMateria const & rhs)
{
	// std::cout << "AMateria copy constructor is called" << std::endl;
	*this = rhs;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor is called" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

AMateria& AMateria::operator=(AMateria const & rhs)
{
	// std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string const & AMateria::getType() const {return (_type);}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	AMateria::use(ICharacter & target)
{
	(void) target;
	// std::cout << target.getName() << " is attacked with " << _type << std::endl;
}
