#include "../include/WrongDog.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
	std::cout << "WrongDog is contructed" << std::endl;
}

WrongDog::WrongDog(WrongDog const & rhs)
{
	std::cout << "WrongDog copy constructor called" << std::endl;
	*this = rhs;
}

WrongDog::~WrongDog()
{
	std::cout << type << " type WrongAnimal is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

WrongDog&	WrongDog::operator=(WrongDog const & rhs)
{
	std::cout << "WrongDog assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	WrongDog::make_sound() const
{
	std::cout << "Wuf" << std::endl;
}