#include "../include/WrongCat.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat is contructed" << std::endl;
}

WrongCat::WrongCat(WrongCat const & rhs)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat()
{
	std::cout << type << " type WrongAnimal is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

WrongCat&	WrongCat::operator=(WrongCat const & rhs)
{
	std::cout << "WrongCat assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	WrongCat::make_sound() const
{
	std::cout << "Meow" << std::endl;
}