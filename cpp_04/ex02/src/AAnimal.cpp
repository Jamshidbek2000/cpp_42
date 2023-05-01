#include "../include/AAnimal.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "Default AAnimal" << " is contructed" << std::endl;
}

AAnimal::AAnimal(std::string const & type) : type(type)
{
	std::cout << type << " AAnimal is contructed" << std::endl;
}

AAnimal::AAnimal(AAnimal const & rhs)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = rhs;
}

AAnimal::~AAnimal()
{
	std::cout << type << " type AAnimal is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

AAnimal&	AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << "AAnimal assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}
