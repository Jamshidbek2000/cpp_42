#include "../include/WrongAnimal.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Default WrongAnimal" << " is contructed" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const & type) : type(type)
{
	std::cout << type << " WrongAnimal is contructed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & rhs)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << type << " type WrongAnimal is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << "WrongAnimal assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	WrongAnimal::make_sound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
